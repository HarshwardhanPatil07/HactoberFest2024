#Change the 'input_image.jpg'  to any other image 




#import the opencv package and matplotlib package
import cv2
import matplotlib.pyplot as plt 
imagepath = 'input_image.jpg'

#Read the image
img = cv2.imread(imagepath)

#Convert the image to greyscale
grey_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


#Load the Classifier
face_classifier = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

#Perform the Face Detection
face = face_classifier.detectMultiScale(grey_image, scaleFactor=1.1, minNeighbors=5, minSize= (40, 40))

#Drawing the Bounding Box
for (x, y, w, h) in face:
    cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 4)

#Displaying the image 
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

plt.figure(figsize=(20, 10))
plt.imshow(img_rgb)
plt.axis('off')
