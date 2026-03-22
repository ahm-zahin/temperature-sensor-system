#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class TempSensor{
    private:
        string name;
        float temp;

    public:
        TempSensor(string n, float t){
            name=n;
            temp=t;
        }

    float getvalue(){
        return temp;
    }
    string getname(){
        return name;
    }   

};

int main(){
    bool a=true;
    ofstream write("data2.txt");
    while(a){
        string dataWrite;
        float tempWrite=0.0f;
        int c;
        cout<<"\nTemperature Data Input Menu:"<<endl;
        cout<<"1. write to file"<<endl;
        cout<<"2. exit input"<<endl;
        cin>>c;
        switch(c){
            case 1:
                cout<<"enter room name and temp (in celsius) using space (RoomName Temperature)"<<endl;
                cin>>dataWrite>>tempWrite;            
                write<< dataWrite << " "<< tempWrite <<endl;
                continue;
            case 2:
                cout<<"closing file and entering calc..."<<endl;
                a=false;
                break;
            default:
                cout<<"invalid choice"<<endl;
                continue;
        }
    }
    write.close();

    ifstream read("data2.txt");
    vector<TempSensor> sensors;

    string name;
    float temp;
    while(read>>name>>temp){
        sensors.push_back(TempSensor(name, temp));
    }
    read.close();

    int size = sensors.size();
    if(size == 0){
        cout << "No data found!" << endl;
        return 0;
    }

    float avgTemp = 0.0f;
    bool b=true;
    while(b){
        cout<<"\nTemperature Calculation Menu:"<<endl;
        cout<<"1. find highest temp"<<endl;
        cout<<"2. find lowest temp"<<endl;
        cout<<"3. find average temp"<<endl;
        cout<<"4. show all sensors"<<endl;
        cout<<"5. show hot rooms (above 25°C)"<<endl;
        cout<<"6. exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1: {
                float maxTempValue = sensors[0].getvalue();
                string maxTempSensor = sensors[0].getname();
                for (int i=0; i<size; i++){
                    if(sensors[i].getvalue()>maxTempValue){
                        maxTempValue=sensors[i].getvalue();
                        maxTempSensor=sensors[i].getname();
                    }
                }
                cout<<"highest temp: "<<maxTempValue<<"°C, sensor: "
                    <<maxTempSensor<<endl;
                continue;
            }
            case 2: {
                float minTempValue = sensors[0].getvalue();
                string minTempSensor = sensors[0].getname();
                for (int i=0; i<size; i++){
                    if(sensors[i].getvalue()<minTempValue){
                        minTempValue = sensors[i].getvalue();
                        minTempSensor = sensors[i].getname();
                    }
                }
                cout<<"lowest temp: "<<minTempValue<<"°C, sensor: "
                    <<minTempSensor<<endl;
                continue;
            }
            case 3: {
                float sumTemp = 0.0f;
                for(int i=0; i<size; i++){
                    sumTemp += sensors[i].getvalue();
                }
                avgTemp = sumTemp/size;
                cout<<"average temp: "<<avgTemp<<"°C"<<endl;
                continue;
            }
            case 4: {
                cout<<"Sensor data:"<<endl;
                for(int i=0; i<size; i++){
                    cout<<"Room: "<<sensors[i].getname()<<" ---> Temperature: "<<sensors[i].getvalue()<<"°C"<<endl;
                }
                continue;
            }
            case 5: {
                cout<<"Hot rooms (above 25°C):"<<endl;
                for(int i=0; i<size; i++){
                    if(sensors[i].getvalue() > 25.0f){
                        cout<<"Room: "<<sensors[i].getname()<<" ---> Temperature: "<<sensors[i].getvalue()<<"°C"<<endl;
                    }
                }
                continue;
            }
            case 6: {
                cout<<"exiting..."<<endl;
                b=false;
                break;
            }
            default:
                cout<<"invalid choice"<<endl;
                continue;
        }   
    }

}
 
