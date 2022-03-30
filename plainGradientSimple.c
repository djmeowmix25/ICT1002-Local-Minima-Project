def run(x_vector, step):
  for i in range(x_vector):
    x_vector[i] = x_vector[i] - step * grad[i]

  return x_vector
