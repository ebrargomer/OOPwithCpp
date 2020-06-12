#include "Layer.h"
#include <iostream>
using namespace std;

Layer::Layer(float* values,int neur,int type) {
	acarray = new float[neur];
	if (type == 0){
		array = new SigmoidNeuron[neur];
		for (int i = 0; i < neur; i++) {
			array[i] = SigmoidNeuron(values[i]);
			acarray[i]=array[i].getValue();
		} 
	}			
	else if (type == 1){
		 array = new LReluNeuron[neur];
		 for (int i = 0; i < neur; i++) {
			array[i] = LReluNeuron(values[i]);
			acarray[i]=array[i].getValue();
		} 
	}
	else if (type == 2){
		array = new ReluNeuron[neur];
		for (int i = 0; i < neur; i++) {
			array[i] = ReluNeuron(values[i]);
			acarray[i]=array[i].getValue();
		} 
	} 
	else if(type>2|| type<0) throw "Unidentified activation function!";
} 
Layer::Layer(float* x,int size, int neur,int type) {
	if (type == 0)	array = new SigmoidNeuron[neur];
	else if (type == 1)array = new LReluNeuron[neur];
	else if (type == 2)	array = new ReluNeuron[neur];
	else if(type>2|| type<0) throw "Unidentified activation function!";
	float w[10][10];
	if(neur>10 && size>10) w[20][20];
	for (int i = 0; i < neur; i++) {
		for (int j = 0; j < size; j++) 
			w[i][j] = 0.1;
	}//w matrices
	
	float* b = new float[neur]; // b matrices
	
	for(int i=0;i<neur;i++) b[i]=0.1;
	float sum = 0;
	for (int i = 0; i < neur; i++) {
		for (int j = 0; j < size; j++) {
			sum += w[i][j]* x[j];
		}
		sum +=b[i];
		if(type==0) 		{array[i] =SigmoidNeuron(sum);array[i].activate(sum);}
		else if (type==1)	{array[i] =LReluNeuron(sum);array[i].activate(sum);}
		else if (type==2) 	{array[i] = ReluNeuron(sum);array[i].activate(sum);}
		sum=0;
	}
	acarray = new float[neur];
	for (int i = 0; i <neur; i++) 	acarray[i]=array[i].getAcValue();

	delete []b;
}
