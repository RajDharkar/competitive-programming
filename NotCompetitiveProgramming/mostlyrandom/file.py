import os
from pathlib import Path

# Define file categories and their extensions
DIRECTORIES = {
    "HTML": [".html5", ".html", ".htm", ".xhtml"],
    "IMAGES": [".jpeg", ".jpg", ".tiff", ".gif", ".bmp", ".png", ".bpg", ".svg",
               ".heif", ".psd"],
    "VIDEOS": [".avi", ".flv", ".wmv", ".mov", ".mp4", ".webm", ".vob", ".mng",
               ".qt", ".mpg", ".mpeg", ".3gp"],
    "DOCUMENTS": [".oxps", ".epub", ".pages", ".docx", ".doc", ".fdf", ".ods",
                  ".odt", ".pwi", ".xsn", ".xps", ".dotx", ".docm", ".dox",
                  ".rvg", ".rtf", ".rtfd", ".wpd", ".xls", ".xlsx", ".ppt",
                  ".pptx"],
    "ARCHIVES": [".a", ".ar", ".cpio", ".iso", ".tar", ".gz", ".rz", ".7z",
                 ".dmg", ".rar", ".xar", ".zip"],
    "AUDIO": [".aac", ".aa", ".aac", ".dvf", ".m4a", ".m4b", ".m4p", ".mp3",
              ".msv", ".ogg", ".oga", ".raw", ".vox", ".wav", ".wma"],
    "PLAINTEXT": [".txt", ".in", ".out"],
    "PDF": [".pdf"],
    "PYTHON": [".py"],
    "XML": [".xml"],
    "EXE": [".exe"],
    "SHELL": [".sh"],
    "JAVA": [".java"],
    "C++": [".cpp"],
    "C": [".c"],
    "AVIF": [".avif"]
}

# Create a reverse mapping of file extensions to directory names
FILE_FORMATS = {file_format: directory
                for directory, file_formats in DIRECTORIES.items()
                for file_format in file_formats}

def organize_junk(download_folder):
    download_folder = Path(download_folder)  # Ensure the path is a Path object
    if not download_folder.exists():
        print(f"The folder '{download_folder}' does not exist.")
        return

    # Categorize files
    for entry in os.scandir(download_folder):
        if entry.is_dir():
            continue  # Skip directories

        file_path = Path(entry.path)
        file_format = file_path.suffix.lower()
        
        # Check if the file format exists in the defined categories
        if file_format in FILE_FORMATS:
            directory_name = FILE_FORMATS[file_format]
        else:
            directory_name = "OTHER"  # Uncategorized files

        # Create the target directory if it doesn't exist
        directory_path = download_folder / directory_name
        directory_path.mkdir(exist_ok=True)

        # Move the file
        try:
            file_path.rename(directory_path / file_path.name)
            print(f"Moved: {file_path.name} -> {directory_path}")
        except Exception as e:
            print(f"Error moving {file_path.name}: {e}")

    # Attempt to remove empty directories
    for dir in os.scandir(download_folder):
        try:
            os.rmdir(dir.path)
        except Exception:
            pass  # Ignore non-empty directories

if __name__ == "__main__":
    download_folder = r'C:\Users\rajve\Downloads'  # Specify your Downloads folder
    organize_junk(download_folder)
