#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <sstream>
#include <list>
#include <chrono>
#include <iomanip>
#include <queue>
#include "hospital.hpp"

using namespace std;

Patient::Patient(string personId, string name)
{
this->personId=personId;
this->name=name;
patientId="";
birthDate=0;
sex='\0';
discharged=false;
vemergency.clear();
ventrance.clear();

}

Patient::Patient(string personId, string name, string patientId, time_t birthDate, char sex, short int emergency, time_t ymd)
{
if((!personId.empty()) && (!name.empty()) && (!patientId.empty()) && (sex=='M') || (sex=='F') && (emergency<5) && (emergency>=0))
{
this->personId=personId;
this->name=name;
this->patientId=patientId;
this->birthDate=birthDate;
this->sex=sex;
discharged=false;
vemergency.push_back(emergency);
ventrance.push_back(ymd);
}
else
{
  this->personId=personId;
this->name=name;
patientId="";
birthDate=0;
sex='\0';
discharged=false;
vemergency.clear();
ventrance.clear();
}
}
string Patient::getPersonId() const
{
return personId;
}

string Patient::getName() const
{
return name;
}

string Patient::getPatientId() const
{
return patientId;
}

time_t Patient::getBirthDate() const
{
return birthDate;
}

char Patient::getSex() const
{
return sex;
}

bool Patient::getDischarged() const
{
return discharged;
}

vector<short int> Patient::getVemergency() const
{
return vemergency;
}

vector<time_t> Patient::getVentrance() const
{
return ventrance;
}

void Patient::setName(string name)
{
if(!name.empty()) {
  this->name=name;
}
}

void Patient::setPatientId(string patientId)
{
if(!name.empty()){
  this->patientId=patientId;
}
}

void Patient::setBirthDate(time_t birthDate)
{
this->birthDate=birthDate;
}

void Patient::setSex(char sex)
{
if(sex=='M' || sex=='F') {
  this->sex=sex;
}
}

void Patient::setDischarged(bool discharged)
{
discharged=discharged;
}

void Patient::addVentrance(time_t ymd)
{
ventrance.push_back(ymd);
}

void Patient::addVemergency(short int emergency)
{
 vemergency.push_back(emergency);
}

PatientManagement::PatientManagement()
{
  listPatient.clear();
}

PatientManagement::~PatientManagement()
{

}

list<Patient *> PatientManagement::getListPatient() const
{
  return listPatient;
}

size_t PatientManagement::getSize() const
{
  return listPatient.size();
}

int PatientManagement::getSizeDay(time_t ymd) const
{
  vector<int> ventrance;
  if(ventrance.size()!=0){
    return ventrance.size();
  }
  else return -1;
}

int PatientManagement::patientInsert(Patient *p)
{

}

Patient *PatientManagement::patientRemove(const string id)
{

}


int PatientManagement::import(const string name_file)
{
  if (name_file.empty())
    return -1;
  
  ifstream f(name_file);
  if (!f)
    return -1;

  string PersonId, name, PatientId;
  int emergency;
  char sex;
  time_t ymd, birth;
  Patient *p;
  int result;
  string s;
  stringstream ss, ssd;
  char delim = ',';
  tm *timeptr = new tm{};
  string date_time_format = "%m/%d/%Y";

  while (getline(f, s)) {
    ss.clear();
    ss << s;
    getline(ss, PersonId, delim);
    getline(ss, name, delim);
    getline(ss, s, delim);
    sex = s[0];
    
    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    birth = mktime(timeptr);

    getline(ss, PatientId, delim);
    
    getline(ss, s, delim);
    emergency = stoi(s);

    getline(ss, s, delim);
    ssd.clear();
    ssd << s;
    getline(ssd, s, '/');
    timeptr->tm_mday = stoi(s);
    getline(ssd, s, '/');
    timeptr->tm_mon = stoi(s);
    getline(ssd, s, ' ');
    timeptr->tm_year = stoi(s);
    ymd = mktime(timeptr);

    p = new Patient(PersonId, name, PatientId, birth, sex, emergency, ymd);

    if (!p) {
      delete p;
      f.close();
      return -1;
    }

    result = patientInsert(p);
    if (result == -1) {
      delete p;
      f.close();
      return -1;
    }
  }

  f.close();
  delete timeptr;
  return 0;
}

list<Patient *> *PatientManagement::searchEmergency(short int emergency)
{

}

EmergencyQueues::EmergencyQueues()
{

}

vector<queue<Patient *> > EmergencyQueues::getEmergencyQueues() const
{
  return vqueueEmergency;
}

size_t EmergencyQueues::getSize(short int emergency) const
{

}

int EmergencyQueues::patientInsert(Patient *p)
{

}

Patient *EmergencyQueues::patientRemove(short int emergency)
{

}

int EmergencyQueues::getPatientsFromList(list<Patient *> listPatient)
{

}

int EmergencyQueues::importDischarged(const string name_file)
{

}

int EmergencyQueues::changeQueue(const string id, short int new_E)
{

}
