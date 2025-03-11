import pyautogui
import keyboard
import time
import pickle

# Function to record actions (mouse movements, clicks, scrolls, and key presses)
def record_macro():
    print("Recording... Press 'esc' to stop.")
    actions = []
    last_mouse_position = pyautogui.position()

    while True:
        # Record mouse position (move or click)
        current_mouse_position = pyautogui.position()
        
        # Record mouse movement if the position changes
        if current_mouse_position != last_mouse_position:
            actions.append(('mouse_move', current_mouse_position, time.time()))
            last_mouse_position = current_mouse_position
        
        # Check if mouse clicked
        if pyautogui.mouseDown():
            actions.append(('mouse_click', current_mouse_position, time.time()))

        # Record mouse scroll (scroll up or down)
        if keyboard.is_pressed("up") or keyboard.is_pressed("down"):
            scroll_direction = "up" if keyboard.is_pressed("up") else "down"
            actions.append(('mouse_scroll', scroll_direction, current_mouse_position, time.time()))
        
        # Record keyboard inputs
        for key in keyboard.get_typed_strings(keyboard.record(until="esc")):
            actions.append(('key_press', key, time.time()))
            time.sleep(0.1)
        
        # Check for 'esc' key to stop recording
        if keyboard.is_pressed("esc"):
            break
        
        # Store actions to file
        with open("macro_actions.pkl", "wb") as file:
            pickle.dump(actions, file)

        time.sleep(0.1)  # Adjust delay between recording

    print("Recording stopped.")

# Function to play back the recorded macro continuously with delay
def playback_macro(delay=0.1):
    print("Playing back the macro continuously...")
    try:
        with open("macro_actions.pkl", "rb") as file:
            actions = pickle.load(file)

        last_action_time = time.time()
        
        while True:  # Continuous loop for playback
            current_time = time.time()
            
            for action in actions:
                elapsed_time = current_time - last_action_time
                if elapsed_time < delay:
                    continue  # Wait until the delay has passed
                
                if action[0] == 'mouse_move':
                    x, y = action[1]
                    pyautogui.moveTo(x, y, duration=delay)  # Smooth movement
                elif action[0] == 'mouse_click':
                    x, y = action[1]
                    pyautogui.click(x, y)
                elif action[0] == 'mouse_scroll':
                    direction = action[1]
                    if direction == "up":
                        pyautogui.scroll(10)  # Scroll up
                    elif direction == "down":
                        pyautogui.scroll(-10)  # Scroll down
                elif action[0] == 'key_press':
                    key = action[1]
                    keyboard.write(key)  # Simulate keypress using keyboard module
                
                last_action_time = current_time
                time.sleep(delay)  # Delay after each action
                
    except FileNotFoundError:
        print("No recorded actions found. Please record a macro first.")
    print("Playback complete.")

# Main loop
def main():
    while True:
        print("1: Record Macro")
        print("2: Play Back Macro Continuously")
        print("3: Exit")
        
        choice = input("Select an option: ")
        time.sleep(2)
        if choice == '1':
            record_macro()
        elif choice == '2':
            delay = float(input("Enter delay between actions (in seconds): "))
            playback_macro(delay)
        elif choice == '3':
            print("Exiting.")
            break
        else:
            print("Invalid option, please try again.")

if __name__ == "__main__":
    main()
