import cv2
import cvlib as cv
from cvlib.object_detection import draw_bbox

video_path = "C:\\Users\\91801\\OneDrive\\Desktop\\EXSEL PROJECT\\TRAFFIC\\VIDEOS\\Traffic video 4.mp4"
cap = cv2.VideoCapture(video_path)

count = 0

while True:
    ret, frame = cap.read()
    if not ret:
        break

    count += 1
    if count % 6 != 0:
        continue

    frame = cv2.resize(frame, (1020, 600))
    car_count = 0
    truck_count = 0
    person_count = 0
    other_count = 0
    
    bbox, label, conf = cv.detect_common_objects(frame)
    for obj_label in label:
        if obj_label == 'car':
            car_count += 1
        elif obj_label == 'truck':
            truck_count += 1
        elif obj_label == 'person':
            person_count += 1
        else:
            other_count +=1
    
    total_count = car_count + truck_count + person_count + other_count


        


    output_image = draw_bbox(frame, bbox, label, conf)
    cv2.putText(output_image, f'Car Count: {car_count}', (10, 130), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)
    cv2.putText(output_image, f'Truck Count: {truck_count}', (10, 160), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)
    cv2.putText(output_image, f'Person Count: {person_count}', (10, 190), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)
    cv2.putText(output_image, f'Total Count: {total_count}', (10, 220), cv2.FONT_HERSHEY_COMPLEX_SMALL, 1, (255, 255, 255), 2)


    cv2.imshow("FRAME", output_image)
    
    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
