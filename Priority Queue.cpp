#include <iostream>
using namespace std;

struct Patient{
    string name;
    string gender;
    int contact;
    int priority;
    Patient *next;
};
class PriorityList{
    Patient *head;
    int beds = 10;
    public:
        PriorityList(){
            head = NULL;
        }
        void AddToList(string n, string g, int c, int p){
            Patient *nn = new Patient;
            nn -> name = n;
            nn -> gender = g;
            nn -> contact = c;
            nn -> priority = p;
            nn -> next = NULL;
            if(head == NULL || head -> priority < p){
                nn -> next = head;
                head = nn;
            }
            else{
                Patient *temp = head;
                while(temp -> next != NULL && temp -> next -> priority >= p){
                    temp = temp -> next;
                }
                nn -> next = temp -> next;
                temp -> next = nn;
            }
        }
        void ShowList(){
            Patient *temp = head;
            if(head == NULL){
                cout << "Empty List" << endl;
                return;
            }
            while(temp != NULL){
                cout << temp -> name << " " << temp -> gender << " "<< temp -> contact << endl;
                temp = temp -> next;
            }
        }
        void AssignBed(){
            if(head == NULL){
                cout << "No patients in the list" << endl;
                return;
            }
            if(beds != 0){
                Patient *ptbd = head;
                cout << head -> name << " " << head -> gender << " " << head -> contact << " " << "Has been asssigned a bed in the Hospital" << endl;
                head = head -> next;
                beds -= 1;
                delete ptbd;
                return;
            }
            else{
                cout << "Sorry no beds available at the moment" << endl;
            }
        }
        void checkBedAvailablity(){
            if(beds == 0){
                cout << "Sorry no beds available at the moment";
                return;
            }
            else{
                cout << "Beds Available :" << beds << endl;
            }
        }
        void searchPatient(string n){
            if(head == NULL){
                cout << "No patients registered in the list" << endl;
                return;
            }
            Patient *temp = head;
            while(temp != NULL){
                if(temp -> name == n){
                    cout << "Name :" << temp -> name << " " << "Gender: " << temp -> gender << " " << "Contact Information: " << temp -> contact << " " << "Severity: " << temp -> priority << endl;
                    return;
                }
                else{
                    temp = temp -> next;
                }
            }
            if(temp == NULL){
                cout << "Patient Details Not Found" << endl;
                return;
            }
        }
        void patientStatus(string n){
            int count = 0;
            Patient *temp = head;
            while(temp != NULL){
                if(temp -> name != n){
                    count += 1;
                    temp = temp -> next;
                }
                else{
                    break;
                }
            }
            if(temp == NULL && count == 0){
                cout << "Patient not present in the list" << endl;
                return;
            }
            cout << "Patient " << n << "is " << count << "th in the queue" << endl;
            return;
        }
        void countPatients(){
            Patient *temp = head;
            int count = 0;
            while(temp != NULL){
                count += 1;
                temp = temp -> next;
            }
            cout << "Total Patients on the List: " << count << endl;
        }
        void clearPatientList(){
            while(head != NULL){
                Patient *ptbd = head;
                head = head -> next;
                cout << "List cleared" << endl;
                delete ptbd;
            }
        }
};
int main() {
    PriorityList P;
    int option, m, p;
    string n, g;
    cout << "1) Add patient to List \n 2) Show List \n 3) Assign Bed \n 4) Check Bed Availability \n 5) Search Patient \n 6) Count Patients \n 7) Check Patient Status \n 8) Clear Patient List \n 9) Exit" << endl;
    while(1){
        cout << "Enter option: ";
        cin >> option;
        cin.ignore();
        switch(option){
            case 1:
                cout << "Enter name: ";
                getline(cin, n);
                cout << "Enter gender: ";
                cin >> g;
                cout << "Enter mobile number: ";
                cin >> m;
                cout << "Enter severity in range(1 - 10): ";
                cin >> p;
                while(p < 1 || p > 10){
                    cout << "Enter severity in range(1 - 10): ";
                    cin >> p;
                }
                P.AddToList(n, g, m, p);
                break;
            case 2:
                P.ShowList();
                break;
            case 3:
                P.AssignBed();
                break;
            case 4:
                P.checkBedAvailablity();
                break;
            case 5:
                cout << "\nEnter patient name: ";
                getline(cin, n);
                break;
            case 6:
                P.countPatients();
                break;
            case 7:
                cout << "Enter Patient name: ";
                cin >> n;
                P.patientStatus(n);
                break;
            case 8:
                P.clearPatientList();
            case 9:
                return 0;
        }
    }
    return 0;
}