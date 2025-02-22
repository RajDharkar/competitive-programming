import numpy as np
import cv2
from cvzone.ColorModule import ColorFinder

# Create the color Finder object with debug mode turned off
myColorFinder = ColorFinder(True)
hsvVals = {'hmin': 1, 'smin': 77, 'vmin': 0, 'hmax': 17, 'smax': 255, 'vmax': 255}

# Variables
posListX, posListY = [], []
xList = [item for item in range(0, 1300)]
prediction = False

def arsh_detection():
    # Grab the image
    img = cv2.imread("TestingVision\\lol.png")
    img = img[0:900, :]  # Crop the image

    # Resize for display
    img = cv2.resize(img, (0, 0), None, 0.7, 0.7)

    # Process the image using the ColorFinder update method
    imgColor, mask = myColorFinder.update(img, hsvVals)

    # Apply morphological operations to clean up the mask
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.erode(mask, kernel, iterations=1)
    mask = cv2.dilate(mask, kernel, iterations=2)

    cv2.imshow("Mask with Morphology", mask)

    # Find contours
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Initialize center coordinates
    cX, cY, cZ = 0, 0, 0
    if contours:
        # Filter contours by area (adjust minArea as needed)
        minArea = 1000  # You can adjust this value
        valid_contours = [cnt for cnt in contours if cv2.contourArea(cnt) > minArea]

        if valid_contours:
            largest_contour = max(valid_contours, key=cv2.contourArea)

            # Draw the largest contour
            cv2.drawContours(img, [largest_contour], -1, (0, 255, 0), 3)

            # Find the center of the largest contour
            M = cv2.moments(largest_contour)
            if M["m00"] != 0:
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])
                cv2.circle(img, (cX, cY), 7, (255, 0, 0), -1)

            # Assuming a fixed z-coordinate since it's 2D image data
            cZ = 0  # Placeholder for 3D applications or depth estimation

    # Display the image with contours
    cv2.imshow("Image with Contours", img)
    return cX, cY, cZ

if __name__ == '__main__':
    while True:
        print(arsh_detection())
        # Break the loop if the 'q' key is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
cv2.destroyAllWindows()
