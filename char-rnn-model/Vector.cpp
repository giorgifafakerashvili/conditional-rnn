/**
 *
 *
 */

 #include "Vector.h"
 #include "Matrix.h"

 #include <math.h>
 #include <cblas.h>
 #include <float.h>

 extern bool USE_BLAS;

Vector::Vector(int m) {
  m_ = m;
  data_ = new double[m];
}
Vector::Vector(const Vector& other) {
  m_ = other.m_;
  data_ = new double[m_];
  for(int i = 0; i < m_; ++i) {
    data_[i] = other.data_[i];
  }
}

/**
 * Destrucot will delete
 * every elelent
 */
Vector::~Vector() {
  delete [] data_;
}

void Vector::fillRandom() {
  for(int i = 0; i < m_; ++i) {
    data_[i] = uniRand();
  }
}

void Vector::fillValue(double a) {
  for(int i = 0; i < m_; ++i) {
    data_[i] = a;
  }
}

void Vector::print() {
  for(int i = 0; i < m_; ++i) {
    printf("%+5.2f", data_[i]);
  }
  printf("\n");
}


void Vector::set(int index, double d) {
  assert(index < m_);
  data_[index] = d;
}

double Vector::get(int i) {
  assert(i < m_);
  return data_[i];
}

double Vector::max() {
  double M = -DBL_MAX;
  for(int i = 0; i < m_; ++i) {
    if(data_[i] > M) {
      M = data_[i];
    }
  }

  return M;
}

/**
double Vector::max() {
  return *std::max_element(data_, data_ + m_);
}
*/

void Vector::scale(double a) {
  for(int i = 0; i < m_; ++i) {
    data_[i] *= a;
  }
}

/**
 * Compute dot product between current class
 * and b
 */
double Vector::dot(Vector& b) {
  // their sizes must be the same
  assert(m_ == b.m_);

  double result {0.0};
  for(int i = 0; i < m_; ++i) {
    result += data_[i] * b.data_[i];
  }

  return result;
}

void Vector::copy(Vector& b) {
  assert(m_ == other.m_);
  for(int i = 0; i < m_; ++i) {
    data_[i] = b.data_[i];
  }
}

/**
 * In place update as this = this + b
 */
void Vector::addInPlace(Vector& b) {
  assert(m_ == b.m_);
  for(int i = 0; i < m_; ++i) {
    data_[i] += b.data_[i];
  }
}


/**
 * In place update as this = this * b
 */
void Vector::timesInPlace(Vector& b) {
  /**
   * if(m_ != other.m_) {
   *  throw std::invalid_argument("Vector sizes are different");
   * }
   */
  assert(m_ == other.m_);
  for(int i = 0; i < m_; ++i) {
    data_[i] *= b.data_[i];
  }

}

void Vector::addInPlace(double a, Vector& b) {
  assert(m_ == b.m_);
  for(int i = 0; i < m_; ++i) {
    data_[i] += a * b.data_[i];
  }

}

double Vector::norm2() {
  double result {0.0};
  for(int i = 0; i < m_; ++i) {
    result += data_[i] * data_[i];
  }
  return result;
}

/**
 * Apply sigmoid to vector
 */
void Vector::sigmoid() {
  for(int i = 0; i < m_; ++i) {
    data_[i] = 1.0 / (1 + exp(-data_[i]));
  }
}


void Vector::aTimesOneMinusA() {
  for(int i = 0; i < m_; ++i) {
    data_[i] = data_[i] * (1.0 - data_[i]);
  }
}


void Vector::softMax() {
  double sum {0.0};
  double M = max();
  for(int i = 0; i < m_; ++i) {
    data_[i] = exp(data_[i] - M);
    sum += data_[i];
  }

  for(int i = 0; i < m_; ++i) {
    data_[i] /= sum;
  }

}
