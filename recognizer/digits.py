
# coding: utf-8

# In[2]:

import csv


# ### Dataset Input

# In[3]:

## Train Dataset.
images = [] # Images as vectors
digits = [] # Digits in the images

with open('train.csv', 'rb') as trainfile:
    trainread = csv.reader(trainfile, delimiter=',', quotechar="'")
    trainread.next() # Skips header

    for row in trainread: # Reads image and digit
        digits.append(row[0])
        images.append(row[1:])


# In[4]:

## Test Dataset
test_images = []

with open('test.csv', 'rb') as testfile:
    testread = csv.reader(testfile, delimiter=',', quotechar="'")
    testread.next() # Skips header
    
    for row in testread:
        test_images.append(row)


# ### Submissions

# In[10]:

def submit(prediction,file):
    with open(file + '.csv', 'wb') as outfile:
        predwriter = csv.writer(outfile,delimiter=",",quotechar='|', quoting=csv.QUOTE_MINIMAL)
        
        predwriter.writerow(['ImageId','Label'])
        for i in range(len(prediction)):
            predwriter.writerow([i+1,prediction[i]])


# ### KNN Classifier

# In[4]:

## KNN Classifier
# Training
from sklearn import neighbors
k = 1
knn = neighbors.KNeighborsClassifier(n_neighbors=k)
knn.fit(images, digits)


# In[13]:

# Prediction
knn_prediction = knn.predict(test_images).tolist()


# In[14]:

# Submission
submit(knn_prediction,"digits_knn1.s")


# ###Random Forest

# In[5]:

## Random Forests Classifier
# Training
from sklearn.ensemble import RandomForestClassifier
k = 100
forest = RandomForestClassifier(n_estimators = 100, n_jobs=6)
forest.fit(images, digits)


# In[8]:

# Prediction
forest_prediction = forest.predict(test_images).tolist()


# In[11]:

# Submission
submit(forest_prediction,"forest_digits1")


# ### Naive Bayes

# In[1]:

## Naive Bayes Classifier
# Training
from sklearn.naive_bayes import GaussianNB
nb = GaussianNB()
nb.fit(images, digits)


# In[8]:

# Prediction
nb_prediction = nb.predict(test_images).tolist()


# In[11]:

# Submission
submit(nb_prediction,"nbayes_digits1")

