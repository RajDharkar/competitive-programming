import matplotlib.pyplot as plt
import matplotlib.patches as patches
from PIL import Image

# Path to the background image
background_image_path = "background.jpg"

# Content for the Patriots' propaganda
patriot_content = {
    "title": "Join the Fight for Freedom!",
    "slogan": "No Taxation Without Representation!",
    "arguments": [
        "Fight against British tyranny!",
        "Secure a future of liberty and justice!",
        "Stand up for your rights and freedoms!"
    ],
    "call_to_action": "Join the Patriots today and fight for independence!",
    "justification": """
    The design choices for this Patriot propaganda poster are rooted in the fervent desire for independence and liberty that characterized the American Revolution. 
    The title "Join the Fight for Freedom!" captures the urgency and importance of the cause. The slogan "No Taxation Without Representation!" reflects a core grievance that fueled the revolutionary spirit. 
    The arguments emphasize resistance to British tyranny, the pursuit of justice, and the protection of individual rights. 
    The call to action urges immediate involvement in the fight for independence. 
    The overall design is intended to evoke a sense of patriotism and urgency, compelling individuals to join the Patriots' cause. 
    The background represents the birth of the new nation, and the bold, colorful text ensures the message stands out and grabs attention.
    """
}

def create_patriot_poster(content, filename):
    # Load the background image
    background_image = Image.open(background_image_path)

    # Create the poster
    fig, ax = plt.subplots(figsize=(8, 12))

    # Set background image to fill the entire poster
    ax.imshow(background_image, aspect='auto')

    # Remove axes
    ax.axis('off')

    # Title banner
    title_banner = patches.Rectangle((0, 0.8), 1, 0.1, transform=ax.transAxes, color='blue', alpha=0.9)
    ax.add_patch(title_banner)

    # Title
    plt.text(0.5, 0.85, content["title"], fontsize=24, fontweight='bold', ha='center', va='center', color='white')

    # Slogan
    plt.text(0.5, 0.75, content["slogan"], fontsize=20, fontweight='bold', ha='center', va='center', color='red')

    # Arguments
    y_positions = [0.65, 0.6, 0.55]
    for i, argument in enumerate(content["arguments"]):
        plt.text(0.5, y_positions[i], argument, fontsize=16, ha='center', va='center', color='black')

    # Call to action
    plt.text(0.5, 0.45, content["call_to_action"], fontsize=18, fontweight='bold', ha='center', va='center', color='green')

    # Historical elements
    historical_text = [
        "1775: The battles of Lexington and Concord mark the start of the Revolutionary War.",
        "1776: The Declaration of Independence is adopted, proclaiming freedom from British rule.",
        "1781: The British surrender at Yorktown, leading to American victory."
    ]
    for i, hist in enumerate(historical_text):
        plt.text(0.5, 0.3 - i*0.05, hist, fontsize=12, ha='center', va='center', color='darkred')

    # Justification paragraph
    justification_text = content["justification"].strip().replace('\n', ' ')
    plt.text(0.5, 0.05, justification_text, fontsize=12, ha='center', va='center', color='black', wrap=True, bbox=dict(facecolor='white', alpha=0.8))

    # Decorative border
    border = patches.Rectangle((0, 0), 1, 1, transform=ax.transAxes, linewidth=5, edgecolor='black', facecolor='none')
    ax.add_patch(border)

    # Save the poster
    plt.savefig(filename, bbox_inches='tight', pad_inches=0.1)

    # Show the poster
    plt.show()

# Create the Patriots' poster
create_patriot_poster(patriot_content, 'patriot_poster.png')
