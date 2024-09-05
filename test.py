import os
import zipfile

def extract_and_sort_files(zip_path, output_folder):
    # Create output directories
    input_dir = os.path.join(output_folder, 'input')
    output_dir = os.path.join(output_folder, 'output')
    os.makedirs(input_dir, exist_ok=True)
    os.makedirs(output_dir, exist_ok=True)
    
    # Extract the zip file
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(output_folder)
    
    # Initialize counters for naming files
    input_counter = 0
    output_counter = 0
    
    # Iterate over the extracted files
    for root, _, files in os.walk(output_folder):
        # Skip the input and output directories
        if root in [input_dir, output_dir]:
            continue
        for file in files:
            file_path = os.path.join(root, file)
            if file.endswith('.in'):
                new_name = f'input{input_counter:02}.txt'
                os.rename(file_path, os.path.join(input_dir, new_name))
                input_counter += 1
            elif file.endswith('.out'):
                new_name = f'output{output_counter:02}.txt'
                os.rename(file_path, os.path.join(output_dir, new_name))
                output_counter += 1
    
    # Remove any empty directories left in the root
    for dirpath, _, _ in os.walk(output_folder):
        if dirpath != input_dir and dirpath != output_dir:
            os.rmdir(dirpath)

# Example usage:
zip_path = r'C:\Users\meggs\Downloads\tests2.zip'
output_folder = r'C:\Users\meggs\Downloads\problemA2'
extract_and_sort_files(zip_path, output_folder)
