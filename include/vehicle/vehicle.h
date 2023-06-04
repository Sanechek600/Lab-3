#pragma once

#include <memory>
#include <vector>
#include <cstring>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;



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
        virtual void print(ostream& out) = 0;

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
        Train() {
            set_name("stdtrain");
            set_bt(0);
        }
        Train(string name, float base_tariff);

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;
        friend istream& operator>>(istream& in, shared_ptr<Train> item);

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
        Plane() {
            set_name("stdplane");
            set_bt(0);
            _eng_type = 0;
        }
        Plane(string name, float base_tariff, int eng_type);

        int get_et() const;
        void set_et(int et);

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;
        friend istream& operator>>(istream& in, shared_ptr<Plane> item);

        VehiclePtr clone() const override;
        bool equals(VehiclePtr other) const override;
    };



    class Ship : public Vehicle {
    private:
        float _range_mod;
    public:
        Ship() {
            set_name("stdship");
            set_bt(0);
            _range_mod = 1.0;
        }
        Ship(string name, float base_tariff, float range_mod);

        float get_rm() const;
        void set_rm(float range_mod);

        float compute_cost(float mass, float range) const override;
        void print(ostream& out) override;
        friend istream& operator>>(istream& in, shared_ptr<Ship> item);

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

        void add(VehiclePtr v);
        void insert(VehiclePtr v, int index);
        void remove(int index);

        void swap(VehicleList& other);

        void print(ostream& out);
    };


    int index_of_min_cost(const VehicleList& vehicles, float mass, float range);

