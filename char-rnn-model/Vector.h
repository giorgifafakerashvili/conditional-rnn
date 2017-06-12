#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Utils.h"

#include <stdio.h>
#include <assert.h>

/**
 * Declaration of Matrix
 */
class Matrix;

/**
 * Vector implemenation
 */
class Vector {
public:
  Vector();
  Vector(int);
  Vector(const Vector&);
  ~Vector();

  /**
   * Fill vector elemetns with
   * random numbers
   */
  void fillRandom();

  /**
   * Fill vector elments with
   * custom value
   */
   void fillValue(double);

   /**
    * Print elements of the matrix
    */
    void print();

    /**
     * make array element
     * at index i equal to value
     */
     void set(int, double);

     /**
      * get an element at certain
      * index
      */
      double get(int);

      /**
       * Get the maximum element
       */
       double max();

       // level 1 operations

       void scale(double);

       /**
        * Copy vector elelemtns
        */
        void copy(Vector&);

        /**
         * Returns the dot product between two
         * vector
         */
         double dot(Vector&);

         void addInPlace(Vector&);

         void addInPlace(double, Vector&);

         void timesInPlace(double, Vector&);

         double norm2();

         void aTimesOneMinusA();

         void softmax();

         void getColumn(Matrix&, int);
         void getRow(Matrix&, int);

         void addVector(Vector&, Vector&);
         void timesVectors(Vector&, Vector&);

         void matrixVector(double, Matrix&, Vector&, double);
         void matrixTVector(double, Matrix&, Vector&, double);

         int m_;
         double* data_;
};

#endif // _VECTOR_H_
