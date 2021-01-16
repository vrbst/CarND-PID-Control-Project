#include "PID.h"

/**
 * DONE: Complete the PID class. You may add any additional desired functions.
 */

#define DELTA_T 1

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * DONE: Initialize PID coefficients (and errors, if needed)
   */
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  cte_t_minus_one = 0;
  
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;  
}

void PID::UpdateError(double cte) {
  /**
   * DONE: Update PID errors based on cte.
   */
  p_error = cte; //actual cte
  i_error = i_error + cte; //sum of all cte values
  d_error = (cte - cte_t_minus_one) / DELTA_T; 
  cte_t_minus_one = cte;
}

double PID::TotalError() {
  /**
   * DONE: Calculate and return the total error
   */
  return (-1 * Kp * p_error) - (Kd * d_error) - (Ki * i_error);  // TODO: Add your total error calc here!
}

double PID::GetSteerValue(double cte) {
  UpdateError(cte);
  return TotalError();
}
  