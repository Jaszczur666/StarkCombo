#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	vector <int> top,bottom;
	//cout << argc<<endl;
	/*for (int i=0;i<argc;i++){
		cout<< argv[i]<<" ";
	}
	
	cout<<endl;
	*/
	if (argc==2) {
		string name=string(argv[1]);
		//cout <<name<<endl;
		ifstream inpfile(name.c_str()); 
		if (inpfile.is_open()){
			string line;
			getline(inpfile,line);
			stringstream ss(line);
			while (!ss.eof()){
				string x;
				getline(ss,x,',');
				top.push_back(atof(x.c_str()));
			}
				getline(inpfile,line);
			ss.clear();
			ss.str(line);
			while (!ss.eof()){
				string x;
				getline(ss,x,',');
				bottom.push_back(atof(x.c_str()));
			}
			
		}
		
	}

	for (int i=0; i<top.size(); i++) {
		for (int j=0; j<bottom.size(); j++) {
			cout <<top[i]-bottom[j]<<endl;
		}
	}
	double Zi;
	Zi=0;
		for (int i=0; i<top.size(); i++) {
		Zi+=exp(-(top[i]-top[0])/200.0);
		}
		double Zf;
	Zf=0;
		for (int i=0; i<bottom.size(); i++) {
		Zf+=exp(-bottom[i]/200.0);
		}
		//cout <<"Dd "<<Zi<<" "<<Zf<<" "<<Zf/Zi;
	return 0;
}

