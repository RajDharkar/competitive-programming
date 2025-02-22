from fpdf import FPDF

# Define a class for the PDF
class ScratchCurriculumPDF(FPDF):
    def header(self):
        self.set_font("Arial", "B", 14)
        self.cell(0, 10, "Scratch Pac-Man Curriculum", ln=True, align="C")
        self.ln(10)

    def chapter_title(self, title):
        self.set_font("Arial", "B", 12)
        self.cell(0, 10, title, ln=True, align="L")
        self.ln(5)

    def chapter_body(self, body):
        self.set_font("Arial", "", 10)
        self.multi_cell(0, 10, body)
        self.ln()

# Updated curriculum to focus on building a Pac-Man-like game
updated_curriculum = [
    {
        "title": "Unit 1: Introduction to Scratch",
        "content": "Overview of the Scratch interface\n"
                   "Understanding sprites, the stage, and the block palette\n"
                   "Navigating the Scratch community and resources",
    },
    {
        "title": "Unit 2: Creating and Moving Sprites",
        "content": "Adding and customizing sprites\n"
                   "Using motion blocks to control sprite movement\n"
                   "Coordinating multiple sprites in a project",
    },
    {
        "title": "Unit 3: Using Events to Control Actions",
        "content": "Implementing event blocks to trigger actions\n"
                   "Understanding the role of the green flag and other event starters\n"
                   "Creating interactive projects responding to user inputs",
    },
    {
        "title": "Unit 4: Introducing Control Blocks",
        "content": "Utilizing loops (repeat, forever) for repeated actions\n"
                   "Applying conditional statements (if, if-else) for decision-making\n"
                   "Managing the flow of projects with control structures",
    },
    {
        "title": "Unit 5: Working with Variables and Operators",
        "content": "Creating and using variables to store data\n"
                   "Performing mathematical operations with operator blocks\n"
                   "Developing projects that utilize scores, timers, and other dynamic elements",
    },
    {
        "title": "Unit 6: Implementing Collision Detection and Game Logic",
        "content": "Detecting collisions between sprites (e.g., Pac-Man and walls, ghosts, or dots)\n"
                   "Setting up game rules and win/lose conditions\n"
                   "Programming enemy sprite behavior (ghost movement)",
    },
]

# Create a new PDF with the updated curriculum
pdf_updated_curriculum = ScratchCurriculumPDF()
pdf_updated_curriculum.add_page()

# Add content to the PDF
for unit in updated_curriculum:
    pdf_updated_curriculum.chapter_title(unit["title"])
    pdf_updated_curriculum.chapter_body(unit["content"])

# Save the updated PDF
updated_pdf_path = "Scratch_Pacman_Curriculum.pdf"
pdf_updated_curriculum.output(updated_pdf_path)

import os

# Print the absolute path
absolute_path = os.path.abspath(updated_pdf_path)
print(f"PDF saved at {absolute_path}")
