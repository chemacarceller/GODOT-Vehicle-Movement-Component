#ifndef VEHICLE_MOVEMENT_COMPONENT_H
#define VEHICLE_MOVEMENT_COMPONENT_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node3d.hpp>

#include <godot_cpp/classes/rigid_body3d.hpp>

// Using the godot namespace to avoid prefixing all Godot classes with 'godot::'
using namespace godot;


// Basic Vehicle Movement Component
//

class VehicleMovementComponent : public Node {

    GDCLASS(VehicleMovementComponent, Node);
private:

    //################################################################################################
    //#                               E X P O R T E D   V A R I A B L E S                            #
    //################################################################################################

    // The underscore indicates that the variable is exported

    // Property to activate or deactivate the movement
    bool _isEnabled = true;

    // --- INTERNAL / PRIVATE VARIABLES ---

    // myVehicle without access outside because is the ParentActor
    RigidBody3D *myVehicle= nullptr;


protected:
    static void _bind_methods();

public:
    VehicleMovementComponent();
    ~VehicleMovementComponent();

    // Godot lifecycle
    void _notification(int p_what);
    void _ready() override;
    void _physics_process(double delta) override;

    // --- GETTERS & SETTERS (EXPORTED PROPERTIES) ---

    void set_enabled(const bool value) { _isEnabled = value; }
    bool is_enabled() const { return _isEnabled; }
};

#endif