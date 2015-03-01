
# coding: utf-8

# In[1]:

import csv


# ### Dataset Input

# In[2]:

## Train Dataset.
images = [] # Images as vectors
digits = [] # Digits in the images

with open('train.csv', 'rb') as trainfile:
    trainread = csv.reader(trainfile, delimiter=',', quotechar="'")
    trainread.next() # Skips header

    for row in trainread: # Reads image and digit
        digits.append(row[0])
        images.append(row[1:])


# In[3]:

## Test Dataset
test_images = []

with open('test.csv', 'rb') as testfile:
    testread = csv.reader(testfile, delimiter=',', quotechar="'")
    testread.next() # Skips header
    
    for row in testread:
        test_images.append(row)


# ### KNN Classifier

# In[4]:

## KNN Classifier
# Training
from sklearn import neighbors
k = 1
knn = neighbors.KNeighborsClassifier(n_neighbors=k)
knn.fit(images, digits)


# In[5]:

# Prediction
knn_prediction = knn.predict(test_images[0:50]).tolist()


# ###Random Forest

# In[6]:

## Random Forests Classifier
# Training
from sklearn.ensemble import RandomForestClassifier
k = 100
forest = RandomForestClassifier(n_estimators = 100)
forest.fit(images, digits)


# In[7]:

# Prediction
forest_prediction = forest.predict(test_images[0:50]).tolist()


# ### Submissions

# In[1]:

def submit(prediction,file):
    with open(file + '.csv', 'wb') as outfile:
        predwriter = csv.writer(outfile,delimiter="'",quotechar='|', quoting=csv.QUOTE_MINIMAL)
        
        predwriter.writerow(['ImageId','Label'])
        for i in range(len(prediction)):
            predwriter.writerow([i,prediction[i]])

