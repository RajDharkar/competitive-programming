import cadquery as cq

# Define dimensions for the basic GoBilda drivetrain
width = 16 * 25.4  # 16 inches to mm
length = 16 * 25.4  # 16 inches to mm
height = 3 * 25.4  # Basic frame height in mm

# Create the base of the robot using channels (as a square frame)
base_thickness = 5  # Channel thickness in mm
chassis = (
    cq.Workplane("XY")
    .rect(width, length)
    .extrude(base_thickness)
)

# Wheels (approximating them as cylinders for simplicity)
wheel_radius = 2 * 25.4  # 2-inch radius for GoBilda wheels
wheel_thickness = 1.5 * 25.4  # Wheel thickness
wheel_positions = [
    (-width / 2 + wheel_radius, -length / 2 + wheel_radius),
    (width / 2 - wheel_radius, -length / 2 + wheel_radius),
    (-width / 2 + wheel_radius, length / 2 - wheel_radius),
    (width / 2 - wheel_radius, length / 2 - wheel_radius)
]

# Add wheels to the chassis
for pos in wheel_positions:
    wheel = (
        cq.Workplane("XY", origin=(pos[0], pos[1], -wheel_radius))
        .circle(wheel_radius)
        .extrude(wheel_thickness)
    )
    chassis = chassis.union(wheel)

# Create the motors (cylinders for simplicity)
motor_radius = 10  # mm
motor_length = 30  # mm
motor_positions = [
    (-width / 2 + motor_radius * 2, -length / 2 + motor_radius * 2),
    (width / 2 - motor_radius * 2, -length / 2 + motor_radius * 2),
    (-width / 2 + motor_radius * 2, length / 2 - motor_radius * 2),
    (width / 2 - motor_radius * 2, length / 2 - motor_radius * 2)
]

# Add motors
for pos in motor_positions:
    motor = (
        cq.Workplane("XY", origin=(pos[0], pos[1], height))
        .circle(motor_radius)
        .extrude(motor_length)
    )
    chassis = chassis.union(motor)

# Add a simple lift mechanism
# Base of the lift (approx. at the center of the chassis)
lift_base_width = 30  # mm
lift_base_length = 10  # mm
lift_base_height = 60  # mm  (height of the lift base)

lift_base = (
    cq.Workplane("XY", origin=(0, 0, height))
    .box(lift_base_width, lift_base_length, lift_base_height)
)

# Adding an arm to the lift mechanism
arm_length = 200  # mm (length of the arm)
arm_thickness = 5  # mm (thickness of the arm)
arm_width = 15  # mm (width of the arm)

lift_arm = (
    cq.Workplane("XY", origin=(0, lift_base_length / 2, height + lift_base_height))
    .box(arm_length, arm_width, arm_thickness)
)

# Rotate the arm upwards to simulate lifting
lift_arm = lift_arm.rotate((0, 0, 0), (0, 1, 0), 45)

# Combine lift base and arm with the chassis
chassis = chassis.union(lift_base)
chassis = chassis.union(lift_arm)

# Export the model as an STL file
cq.exporters.export(chassis, 'basic_gobilda_ftc_robot_with_lift.stl')

print("CAD model with lift mechanism has been generated and saved as 'basic_gobilda_ftc_robot_with_lift.stl'")
