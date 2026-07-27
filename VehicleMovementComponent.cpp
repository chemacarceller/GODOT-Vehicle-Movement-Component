#include "VehicleMovementComponent.h"

// It provides the interface to ClassDB, Godot's internal database of all registered classes
#include <godot_cpp/core/class_db.hpp>

// Using the godot namespace to avoid prefixing all Godot classes with 'godot::'
using namespace godot;

// The _bind_methods method is required even if it is empty

void VehicleMovementComponent::_bind_methods() {

    // Record of methods for Godot to see
    ClassDB::bind_method(D_METHOD("set_enabled", "value"), &VehicleMovementComponent::set_enabled);
    ClassDB::bind_method(D_METHOD("is_enabled"), &VehicleMovementComponent::is_enabled);


    // Exporting properties (equivalent to @export)
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "_isEnabled"), "set_enabled", "is_enabled");
}


// Constructor and Destructor

// The constructor and destructor are required even if they are empty

VehicleMovementComponent::VehicleMovementComponent() {}

VehicleMovementComponent::~VehicleMovementComponent() {}


void VehicleMovementComponent::_ready() {

    myVehicle = Object::cast_to<RigidBody3D>(get_parent());

}

void VehicleMovementComponent::_physics_process(double delta) { }

void VehicleMovementComponent::_notification(int p_what) {
    if (p_what == NOTIFICATION_WM_CLOSE_REQUEST) {
        queue_free();
    }
}