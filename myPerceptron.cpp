#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

const int SIZE = 3;

struct Perceptron
{
 public:
    int input[SIZE]; 
    double weight[SIZE]; 
    double threshold;
    bool firing;
    //int bias; 
};  

void InitializeWeights(Perceptron & pct);
//
void GetInput(Perceptron & p, double & total);
//
double PredictorFunction(Perceptron p, double total);
//
void CostFunction(Perceptron & p, double subOutput);
//
void UpdateTotal(Perceptron p, double & total);
//

//*****************************************************************************

int main()
{
    double total = 0;
    double subOutput = 0;
    Perceptron pct;

    pct.threshold = 0.975;
    pct.firing = false;

    InitializeWeights(pct);
    GetInput(pct,total);
    while(not pct.firing)
    {
      subOutput = PredictorFunction(pct,total);
      if(subOutput >= pct.threshold)
      {
        pct.firing = true;
        cout << "The perceptron has fired!" << endl;
        cout << subOutput << endl;
      }
      else
      {
        cout << "The perceptron did not fire." << endl;
        cout << subOutput << endl;
        CostFunction(pct, subOutput);
        UpdateTotal(pct, total);
      }
    }

    return 0;
}

//*****************************************************************************

void InitializeWeights(Perceptron & p)
{
  double random = 0.0;
  srand(time(0));
  cout << "Generating random weights..." << endl;
  for(int i = 0; i < SIZE; i++)
  {
      random = rand()%10;
      random = random/10;
      p.weight[i] = random;
      cout << p.weight[i] << endl;
  }
  cout << endl;
  
  return;
}

void GetInput(Perceptron & p, double & total)
{
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Enter input for " << i << "=>";
    cin >> p.input[i];
    cout << endl;
    total += (p.input[i] * p.weight[i]);
  } 

    return;
}

double PredictorFunction(Perceptron p, double total)
{
  return (1/(1+exp(-(total * p.threshold))));
}

void CostFunction(Perceptron & p, double subOutput)
{
  for (int i = 0; i < SIZE; i++)
  {
    p.weight[i] = p.input[i] * (p.threshold - subOutput);
  }

  return; 
}

void UpdateTotal(Perceptron p, double & total)
{
  total = 0.0;
  for (int i = 0; i < SIZE; i++)
  {
    total += (p.input[i] * p.weight[i]);
  }  

  return;
}