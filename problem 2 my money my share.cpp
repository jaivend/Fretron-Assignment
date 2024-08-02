#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void dist_apples() {
    vector<int>wts;
    int wt;
  cout<<"enter-1 to stop"<<endl;
    cout<<"enter weight ";
    while(cin >>wt&&wt !=-1) {
        wts.push_back(wt);
        cout <<"enter weight ";
    }
     int total_amt= 100;
     int ram_amt =50;
     int sham_amt =30;
     int rahim_amt =20;

    int total_wt =accumulate(wts.begin(), wts.end(),0);
    double ram_shr= (double)ram_amt /total_amt*total_wt;
    double sham_shr =(double)sham_amt /total_amt* total_wt;
    double rahim_shr =(double)rahim_amt/ total_amt* total_wt;

    sort(wts.rbegin(),wts.rend());

    vector<int> ram_all,sham_all, rahim_all;
    double ram_wt = 0,sham_wt =0,rahim_wt =0;

    for (int w :wts) {
        if (ram_wt +w <= ram_shr) {
            ram_all.push_back(w);
            ram_wt +=w;
        } else if(sham_wt +w <=sham_shr) {
            sham_all.push_back(w);
            sham_wt+=w;
        } else {
            rahim_all.push_back(w);
            rahim_wt+=w;
        }
    }

    if (abs(ram_wt -ram_shr) >1e-6 || 
        abs(sham_wt -sham_shr)>1e-6 ||
        abs(rahim_wt -rahim_shr)> 1e-6) {
        cout <<"not possible to distribute try with other weights " << endl;
        return;
    }

    cout <<"\nDistribution Result:\n";
    cout <<"Ram : ";
    for(int w:ram_all) {
        cout<<w<< " ";
    }
    cout << "\nSham : ";
    for (int w: sham_all) {
        cout <<w<< " ";
    }
    cout << "\nRahim : ";
    for (int w :rahim_all) {
        cout <<w<< " ";
    }
    cout<<endl;
}
int main() {
    dist_apples();
    return 0;
}
