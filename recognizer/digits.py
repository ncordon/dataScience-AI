# -*- coding: utf-8 -*-
# <nbformat>3.0</nbformat>

# <codecell>

import csv

# <headingcell level=3>

# Dataset Input

# <codecell>

## Train Dataset.
images = [] # Images as vectors
digits = [] # Digits in the images

with open('train.csv', 'rb') as trainfile:
    trainread = csv.reader(trainfile, delimiter=',', quotechar="'")
    trainread.next() # Skips header

    for row in trainread: # Reads image and digit
        digits.append(row[0])
        images.append(row[1:])

# <codecell>

## Test Dataset
test_images = []

with open('test.csv', 'rb') as testfile:
    testread = csv.reader(testfile, delimiter=',', quotechar="'")
    testread.next() # Skips header
    
    for row in testread:
        test_images.append(row)

# <markdowncell>

# ### KNN Classifier

# <codecell>

## KNN Classifier
# Training
from sklearn import neighbors
k = 1
knn = neighbors.KNeighborsClassifier(n_neighbors=k)
knn.fit(images, digits)

# <codecell>

# Prediction
knn_prediction = knn.predict(test_images[0:50]).tolist()

# <markdowncell>

# ### Submissions

# <codecell>

def submit(prediction):
    with open('submission.csv', 'wb') as outfile:
        predwriter = csv.writer(outfile,delimiter="'",quotechar='|', quoting=csv.QUOTE_MINIMAL)
        
        predwriter.writerow(['ImageId','Label'])
        for i in range(len(prediction)):
            predwriter.writerow([i,prediction[i]])

