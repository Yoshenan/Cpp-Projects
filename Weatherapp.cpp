#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
using namespace std;

class Weather{

public:
    string date;
    double temperature;
    double humidity;
    double rainfall;



    Weather(string d , double t ,double h , double r){
     date = d;
     temperature = t;
     humidity =h;
     rainfall=r;

    }

};

class WeatherAnalyzer{
private :
    vector <Weather> weather;
public:
    void addRecord(const Weather& w){
     weather.push_back(w);

    }

    double calculateAverageTemp()const {
      double sum = 0.0;
       for(const auto& w : weather)
         sum+= w.temperature;

       return sum/weather.size();


    }

    double findMaxRain()const {

     double maxRain = weather[0].rainfall;
     for(const auto& w : weather){
            if(w.rainfall > maxRain) maxRain = w.rainfall;
                return maxRain;



     }


    }

    double findMinTemp()const{
      double minTemp = weather[0].temperature;
      for(const auto& w : weather){
        if(w.temperature < minTemp) minTemp = w.temperature;
            return minTemp;



      }

    }

    void Display() const {
        cout << "\nDate\t\tTemp\tHumidity\tRainfall\n";
        cout << "-------------------------------------------\n";
        for(const auto& w : weather){
            cout<<w.date<<"/t"<<w.temperature<<"/t"<<w.rainfall<<"/t"<<w.humidity<<endl;
        }

    }




};




int main(){

    WeatherAnalyzer Analyzer;

    Analyzer.addRecord(Weather("2025-01-01", 29.5, 78, 2.3));
    Analyzer.addRecord(Weather("2025-07-07", 30, 80, 2.5));
    Analyzer.addRecord(Weather("2025-08-08", 35, 76, 2.1));

    Analyzer.Display();

    cout << "\nAverage Temperature: " << Analyzer.calculateAverageTemp() << "°C\n";
    cout << "Highest Rainfall: " << Analyzer.findMaxRain() << " mm\n";
    cout << "Lowest Temperature: " << Analyzer.findMinTemp() << "°C\n";

    return 0;




}
