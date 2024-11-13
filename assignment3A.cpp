#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

// Line class to represent each railway line.
class Line {
    string lineName;

public:
    Line(const string& name) : lineName(name) {}

    string getLineName() const {
        return lineName;
    }

    void printLineInfo() const {
        cout << "Line: " << lineName << endl;
    }
};

// Platform class to manage train timings.
class Platform {
    int platformNumber;
    set<int> stoppageTimings;
    set<int> throughTimings;

public:
    Platform(int number) : platformNumber(number) {}

    bool addStoppage(int time) {
        if (!validateStoppageTime(time)) {
            throw invalid_argument("Stoppage time must be 30 minutes apart.");
        }
        stoppageTimings.insert(time);
        return true;
    }

    bool addThrough(int time) {
        if (!validateThroughTime(time)) {
            throw invalid_argument("Through time must be 10 minutes apart.");
        }
        throughTimings.insert(time);
        return true;
    }

    int getPlatformNumber() const {
        return platformNumber;
    }

    void printPlatformInfo() const {
        cout << "Platform Number: " << platformNumber << endl;
        cout << "Stoppage Times: ";
        for (const auto& time : stoppageTimings) {
            cout << time << " ";
        }
        cout << "\nThrough Times: ";
        for (const auto& time : throughTimings) {
            cout << time << " ";
        }
        cout << endl;
    }

private:
    bool validateStoppageTime(int time) const {
        for (int t : stoppageTimings) {
            if (abs(t - time) < 30) return false;
        }
        return true;
    }

    bool validateThroughTime(int time) const {
        for (int t : throughTimings) {
            if (abs(t - time) < 10) return false;
        }
        return true;
    }
};

// Template class for Station, allowing ID as int or string.
template <typename T>
class Station {
    T stationID;
    vector<Line> lines;
    Platform platform;

public:
    Station(T id, int platformNumber) : stationID(id), platform(platformNumber) {}

    void addLine(const Line& line) {
        lines.push_back(line);
    }

    void addStoppageTime(int time) {
        platform.addStoppage(time);
    }

    void addThroughTime(int time) {
        platform.addThrough(time);
    }

    T getStationID() const {
        return stationID;
    }

    void printStationInfo() const {
        cout << "Station ID: " << stationID << endl;
        cout << "Lines:" << endl;
        for (const auto& line : lines) {
            line.printLineInfo();
        }
        platform.printPlatformInfo();
    }
};

// Main test program
int main() {
    try {
        string stationID;
        cout << "Enter Station ID (string): ";
        cin >> stationID;
        assert(!stationID.empty() && "Station ID should not be empty.");
        Station<string> station(stationID, 1);

        cout << "Adding lines to the station (Type 'done' to stop): " << endl;
        string lineName;
        while (true) {
            cout << "Enter line name: ";
            cin >> lineName;
            if (lineName == "done") break;
            Line line(lineName);
            station.addLine(line);
        }

        cout << "Adding stoppage times (Type -1 to stop): " << endl;
        int stoppageTime;
        while (true) {
            cout << "Enter stoppage time: ";
            cin >> stoppageTime;
            if (stoppageTime == -1) break;
            station.addStoppageTime(stoppageTime);
        }

        cout << "Adding through times (Type -1 to stop): " << endl;
        int throughTime;
        while (true) {
            cout << "Enter through time: ";
            cin >> throughTime;
            if (throughTime == -1) break;
            station.addThroughTime(throughTime);
        }

        station.printStationInfo();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
