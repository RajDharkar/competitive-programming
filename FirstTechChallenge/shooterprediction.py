import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def projectile_motion(v0, h0, g=386.088):
    # Function to simulate projectile motion
    def motion(t):
        return -0.5 * g * t**2 + v0 * t + h0
    
    return motion

def calculate_velocity(trajectory, h0, g=386.088):
    # Fit the trajectory to find the best velocity
    def model(t, v0):
        return -0.5 * g * t**2 + v0 * t + h0

    times = np.arange(len(trajectory))
    popt, _ = curve_fit(model, times, trajectory, p0=[100])
    
    return popt[0]

def draw_trajectory():
    print("Draw the desired trajectory by clicking on the plot.")
    print("Press Enter when done.")

    # Set up the plot
    fig, ax = plt.subplots()
    ax.set_title('Draw the Desired Trajectory')
    ax.set_xlabel('Horizontal Distance (inches)')
    ax.set_ylabel('Vertical Height (inches)')

    # Variables to store the points
    points = []

    # Function to capture clicks
    def onclick(event):
        if event.inaxes is not None:
            x, y = event.xdata, event.ydata
            points.append((x, y))
            ax.plot(x, y, 'ro')
            fig.canvas.draw()

    cid = fig.canvas.mpl_connect('button_press_event', onclick)
    plt.show()

    # Convert points to arrays for processing
    points = np.array(points)
    x, y = points[:, 0], points[:, 1]

    # Fit the trajectory
    def fit_func(t, v0):
        return -0.5 * 386.088 * t**2 + v0 * t + min(y)

    # Estimate times based on x values
    times = np.linspace(0, len(x), num=len(x))

    # Calculate the required velocity
    velocity = calculate_velocity(y, min(y))
    
    print(f"Estimated Initial Velocity: {velocity:.2f} inches per second")

# Call the function to draw trajectory and compute velocity
draw_trajectory()
