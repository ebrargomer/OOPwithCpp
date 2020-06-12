
#include <fstream>
#include <iostream>
#include <cstring>
#include "Layer.cpp"

using namespace std;
int main(int argc, char *argv[])
{
	ifstream read(argv[1]);
	int layer;
	read>>layer;

	Network mynetwork;
	mynetwork.l_array = new Layer[layer];

	int *neurons= new int[layer];
	for (int i = 0; i<layer; i++)read>>neurons[i];

	int* type_neurons= new int[layer];
	for (int i = 0; i<layer; i++)read >> type_neurons[i];

	float* value= new float[neurons[0]];
	for (int i = 0; i<layer; i++)read >> value[i];
	
	try{
		bool t=(read.eof());
		if(!t)	throw -1;
		else t=true;
	}
	catch(int){
		cout<<"Input shape does not match!"<<endl;
		return -1;
	}
	try{
		mynetwork.l_array[0]=Layer(value, neurons[0], type_neurons[0]);//first layer
	}
	catch(const char*){
		cout<<"Unidentified activation function!";
		return -1;
	}


	float* valu = new float[10];
	valu=value;
	
	int i=1;
	while( i < layer) {
		try{
			mynetwork.l_array[i]=Layer(valu, neurons[i-1],neurons[i], type_neurons[i]);	
		}
		catch(const char*){
			cout<<"Unidentified activation function!";
			return -1;
		}
		valu = mynetwork.l_array[i].getAcArray();
		i++;
	}
	mynetwork.printNetwork(layer,neurons);
	
	delete [] neurons;
	delete [] type_neurons;
	delete [] value;
	delete [] valu;
	return 0;
}
