#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

constexpr uint32_t n_trials = 1024;
constexpr uint32_t max_sample_size = 16384;
constexpr uint32_t n_dim = 10;

std::vector<double> generate_random_points(uint32_t count) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> distrib(0.0, 1.0);

  std::vector<double> points(count);
  for (auto &p : points) {
    p = distrib(gen);
  }
  return points;
}

double eval_multidim_monte_carlo(uint32_t n_samples, uint32_t ndim,
                                 std::function<double(std::vector<double>)> f) {
  double avg = 0.0;
  for (uint32_t i = 0; i < n_trials; ++i) {
    double avg_samples = 0.0;
    for (uint32_t j = 0; j < n_samples; ++j) {
      avg_samples += f(std::move(generate_random_points(ndim)));
    }
    avg += avg_samples / n_samples;
  }
  return avg / n_trials;
}

struct IntBound {
  double lower = 0.0;
  double upper = 0.0;
};

double monteCarloMethod(double (*f)(std::vector<double> x),
                        const std::vector<IntBound> &bounds) {

  double result = eval_multidim_monte_carlo(max_sample_size, bounds.size(), f);
  for (const auto &bound : bounds) {
    result *= (bound.upper - bound.lower);
  }
  return result;
}

auto f = [](std::vector<double> x) {
  double sum = 0.0;
  for (auto xi : x) {
    sum += xi;
  }
  return sum * sum;
};

int main(int argc, char **argv) {
  std::chrono::high_resolution_clock clock;

  auto c_start = clock.now();

  std::vector<IntBound> bounds{{0, 1}, {-1, 1}};
  std::cout << std::setprecision(15) << monteCarloMethod(f, bounds) << '\n';

  auto c_end = clock.now();
  std::cout << "Time eslapsed: " << (c_end - c_start).count() / 1e6 << " ms.\n";

  return 0;
}