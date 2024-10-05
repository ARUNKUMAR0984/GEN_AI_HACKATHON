import cv2
import cvlib as cv
from cvlib.object_detection import draw_bbox
import os

# Path to the folder containing images
folder_path = "C:\\Users\\91801\\OneDrive\\Desktop\\TRANSPORTATION SECTOR\\OTHER\\IMAGE CAPTURED"

# Initialize image count
image_count = 0

# Initialize cumulative counts for vehicles and other objects
total_vehicle_count = 0
total_person_count = 0
total_other_count = 0

# List of traffic-related objects to be categorized as "vehicles"
vehicle_labels = ['car', 'truck', 'bus', 'motorbike', 'bicycle']

# Loop through all files in the folder
for filename in os.listdir(folder_path):
    if filename.endswith(".png") or filename.endswith(".jpg"):  # Check if the file is an image
        image_path = os.path.join(folder_path, filename)  # Construct full file path
        
        # Load the image
        frame = cv2.imread(image_path)

        if frame is None:
            print(f"Error loading image: {filename}")
            continue
        else:
            # Increase the image count
            image_count += 1
            
            # Resize the image for display purposes (optional)
            frame = cv2.resize(frame, (1020, 600))
            
            # Object detection using cvlib
            vehicle_count = 0
            person_count = 0
            other_count = 0

            # Detect common objects in the image
            bbox, label, conf = cv.detect_common_objects(frame)
            
            # Count occurrences of each object
            for obj_label in label:
                if obj_label in vehicle_labels:  # If the detected object is a vehicle
                    vehicle_count += 1
                elif obj_label == 'person':  # Count people separately
                    person_count += 1
                else:  # Other objects not categorized as vehicles or persons
                    other_count += 1

            # Update cumulative totals
            total_vehicle_count += vehicle_count
            total_person_count += person_count
            total_other_count += other_count

            total_count = vehicle_count + person_count + other_count

            # Draw bounding boxes on the image
            output_image = draw_bbox(frame, bbox, label, conf)

            # Display counts on the image
            cv2.putText(output_image, f'Vehicle Count: {vehicle_count}', (10, 130), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)
            cv2.putText(output_image, f'Person Count: {person_count}', (10, 160), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)
            cv2.putText(output_image, f'Total Count: {total_count}', (10, 190), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)

            # Display the image with bounding boxes
            cv2.imshow(f"Output Image - {filename}", output_image)

            # Wait for 1 second before closing the image window
            cv2.waitKey(1000)  # Adjust the time as needed

            # Close the image window
            cv2.destroyAllWindows()
            
            # Print the object counts for the current image
            print(f"Processed image: {filename}")
            print(f"Vehicle Count: {vehicle_count}, Person Count: {person_count}, Other Count: {other_count}, Total Count: {total_count}\n")
            print(f"Cumulative totals so far - Vehicles: {total_vehicle_count}, Persons: {total_person_count}, Others: {total_other_count}\n")
    else:
        print(f"Skipped file: {filename} (not a supported image)")

# Print the total count of images processed
print(f"Total number of images processed: {image_count}")

# Print the final cumulative object counts
final_total = total_vehicle_count + total_person_count + total_other_count
print(f"\nFinal cumulative counts after processing all images:")
print(f"Vehicles: {total_vehicle_count}, Persons: {total_person_count}, Others: {total_other_count}")
print(f"Overall total count of objects: {final_total}")
