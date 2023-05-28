#pragma once

#include <memory>
#include <vector>
#include <cstring>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

namespace vehicle {

    const float PI = 3.141592f;

    const float EPSILON = 0.00001f;



    enum class VType {
        Train,
        Plane,
        Ship
    };



    class Vehicle;

    using VehiclePtr = std::shared_ptr<Vehicle>;

    class Vehicle {
    private:
        string _name;
        float _base_tariff;
    public:
        virtual float compute_cost(float mass, float range) const = 0;
        virtual void print(ostream& out);

        virtual VehiclePtr clone() const = 0;
        virtual bool equals(VehiclePtr other) const = 0;

        virtual ~Vehicle() = default;

        float get_bt() const;
        string get_name() const;
        void set_bt(float bt);
        void set_name(string name);
    protected:
        Vehicle() = default;
        Vehicle(const Vehicle&) = default;
        Vehicle& operator=(const Vehicle&) = default;
    };



    class Train : public Vehicle {
    public:
        Train(string name, float base_tariff);

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };

    enum AirEngType {
        Turboprop,
        Jet
    };

    class Plane : public Vehicle {
    private:
        int _eng_type;
    public:
        Plane(string name, float base_tariff, int eng_type);

        int get_et() const;

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };



    class Ship : public Vehicle {
    private:
        float _range_mod;
    public:
        Ship(string name, float base_tariff, float eng_type);

        float get_rm() const;

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };


    class VehicleList {
    private:
        std::vector<VehiclePtr> _vehicles;
    public:
        VehicleList() = default;

        VehicleList(const VehicleList& other);

        VehicleList& operator=(const VehicleList& rhs);

        int size() const;

        VehiclePtr operator[](int index) const;

        void add(VehiclePtr f);

        void swap(VehicleList& other);

        void print(ostream& out);
    };



    int index_of_min_cost(const VehicleList& vehicles, float mass, float range);
}
