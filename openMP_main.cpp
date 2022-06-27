//openMP main code

#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <bits/stdc++.h>
#include <condition_variable>
#include <omp.h>
#include <chrono>

const int nurse_number = 3;
using namespace std;

using namespace std::chrono;
struct nurse
{
    string name;
    string location;
    bool available;
};
struct History_Pairing
{
    nurse nurse;
    string patientname;
};
vector <string> name;
vector <string> request;
vector <string> location;
vector <History_Pairing> nursehistory;
vector <nurse> Nurse_List;

int countdone = 0 ;
int THREAD_NUMBER = 2;


void GenerateRandomWorker();
void InputPatientData();
nurse WorkerArrangement(int i);
void UpdateNurseStatus();
void SendMessage(nurse working,int order);
void SendAllert(int i);
string FordFulkerson_Worker(nurse nurse, int i);

int main()
{
    //Implement the clock variable
    clock_t starttime,stoptime;

    omp_set_num_threads(THREAD_NUMBER);
    InputPatientData();
    GenerateRandomWorker();

    starttime = clock();
    //WHILE ( TRUE )
    for ( int i = countdone ; i < name.size() - 1;i++)
    {
        //Sequential part
        nurse temp = WorkerArrangement(i);
        //Increase the number of done case in data, so that for the next update of data the program could continue from it but not the beginning of csv
        countdone++;
        #pragma omp sections
        {
            #pragma omp section
            {
                History_Pairing temp2;
                temp2.nurse = temp;
                temp2.patientname = name[i];
                nursehistory.push_back(temp2);
            }
            #pragma omp section
            {
                SendMessage(temp,i);
                SendAllert(i);
            }
        }
    }
    stoptime = clock();
    cout << "Time taken by function: " << (stoptime - starttime)/(CLOCKS_PER_SEC/1000) << " milliseconds" << endl;
}
void InputPatientData()
{
    ifstream data("data.csv");
    string line;
    int counter = 0;
    //Cast the data into csv file
    while(data.good())
    {
        counter +=1;
        string temp1,temp2,temp3;
        getline(data,temp1,',');
        name.push_back(temp1);
        getline(data,temp2,',');
        request.push_back(temp2);
        getline(data,temp3,'\n');
        location.push_back(temp3);
    }
    for ( int i = 0 ; i < counter - 1 ; i ++)
    {
        cout << "name "  << name[i] << " quest " << request[i] << " loca " << location[i] << endl;
    }
}

void GenerateRandomWorker()
{
    srand(time(0));
    string locations[] = {"1", "2", "3"};
    for ( int i = 0 ; i < nurse_number ; i++)
    {
        stringstream ss;
        ss<<i;
        string s;
        ss>>s;

        nurse temp;
        temp.name = "Nurse " + s;
        temp.location = locations[rand()%3];
        temp.available = true;
        Nurse_List.push_back(temp);
    }
}

nurse WorkerArrangement(int i)
{
    cout << endl;
    bool found = false;
    bool special = false;
    while ( found != true )
    {
        UpdateNurseStatus();         //Update the worker status in list for every loop to see if there is any new free worker to current patient

        //First loop to find the worker that both free and nearby the patient
        for ( auto &nurse : Nurse_List)
        {
            if ( (nurse.available == true) && (nurse.location == location[i]))
            {
                nurse.available = false;
                found = true;
                special = true;
                return nurse;
            }
        }
        //Second loop ( if there's no nearby free worker, choose the first found available worker
        for ( auto &nurse : Nurse_List)
        {
            if ( nurse.available == true )
            {
                nurse.available = false;
                found = true;
                return nurse;
            }
        }
        //The loop continues until find the worker for the patient
    }
}

void UpdateNurseStatus()
{
    //This function simulate the ability to change worker's available status when they're done their previous job an update to the system using phone
}

void SendMessage(nurse working,int order)
{
    //This function simulate the function that will send message to worker's phone when they are arranged to new patient's activity
    cout << working.name << " Let's go help "  << name[order] << " with " << request[order] << " at " << location[order] << endl;
    cout << "Direction : " << FordFulkerson_Worker(working,order) << " for " << working.name << " to get to " << name[order] << endl;

}
//Ford Fulkerson with input of worker and patient
string FordFulkerson_Worker(nurse nurse, int i)
{
    //This function simulate the algorithm to find the fastest way from worker's location to user
    return "Ford Fulkerson simulated";
}
void SendAllert(int i)
{
    cout << " . . . Message sent to patient : " << name[i] << " about the coming nurse" << endl;
}