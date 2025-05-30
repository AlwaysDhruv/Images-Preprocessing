import os
import sys
from PIL import Image

def preprocess_image(path):
    img = Image.open(path).convert("L")
    img = img.resize((28, 28))
    pixels = [float(p) / 255.0 for p in img.getdata()]
    return pixels

def find_images_recursively(root_folder):
    valid_exts = (".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff")
    image_paths = []
    for root, _, files in os.walk(root_folder):
        for file in files:
            if file.lower().endswith(valid_exts):
                image_paths.append(os.path.join(root, file))
    return image_paths

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python preprocess.py <dataset_folder> <output_name>")
        sys.exit(1)

    dataset_folder = sys.argv[1]
    name = sys.argv[2]
    image_paths = find_images_recursively(dataset_folder)

    if not image_paths:
        print("No images found.")
        sys.exit(1)

    # Ensure the 'pixels' folder exists
    os.makedirs("pixels", exist_ok=True)

    output_path = os.path.join("pixels", name + ".txt")

    with open(output_path, "w") as out_file:
        for path in image_paths:
            try:
                pixels = preprocess_image(path)
                if len(pixels) != 784:
                    raise ValueError("Invalid pixel count")
                out_file.write(",".join(map(str, pixels)) + "\n")
            except Exception as e:
                print(f"Error processing {path}: {e}")