
#ifndef _LAYER_H
#define _LAYER_H_
#include "Neuron.h"
class Layer
{
protected:
	Neuron* array;
	float* acarray;
public:
	Layer() {};
	Layer(float* values, int neur, int type); //LAYER 0
	Layer(float* x, int size, int neur, int type);//Other Layers
	float* const getAcArray() {
		return acarray;
	}
	void printValues(int size){
		for(int i =0;i<size;i++)cout<<acarray[i]<<endl;	
	}
	~Layer() {
		delete[] array;
	}
};
#endif // !LAYER_H


class Network
{
public:
	Network() {};
	Layer* l_array;
	void printNetwork(int layer, int* neurs){
		float valu[10];
		for(int i=0;i<layer;i++){
			cout<<"Layer"<<i<<":"<<endl;
			l_array[i].printValues(neurs[i]);
		}
	}
};

