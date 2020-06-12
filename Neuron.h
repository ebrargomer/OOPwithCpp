#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class Neuron
{
	protected:
		float value;
		float activatedValue;
	public:
		Neuron() {};
		Neuron(float x) :value(x),activatedValue(x) {};
		virtual void activate(double val) = 0;
		float getValue(){return value;}
		float getAcValue(){return activatedValue;}
		~Neuron(){};
};
class LReluNeuron: public Neuron
{
public:
	LReluNeuron() {};
	LReluNeuron(float x) :Neuron(x) {};
	void activate(double val) {	activatedValue = max(0.1 * val, val);	}
};
class ReluNeuron: public Neuron
{
	
public:
	ReluNeuron() {};
	ReluNeuron(float x) :Neuron(x) {};
	void activate(double val) {	activatedValue = max(double(0), val);	}
};
class SigmoidNeuron : public Neuron
{
public:
	SigmoidNeuron() {};
	SigmoidNeuron(float x):Neuron(x){ };
	void activate(double val) {	activatedValue =1/(1 + exp(-val));	}
};


