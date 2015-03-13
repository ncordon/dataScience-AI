
# coding: utf-8

# In[1]:

import csv
import numpy as np


# ### Dataset Input

# In[2]:

## Train Dataset.
images = [] # Images as vectors
digits = [] # Digits in the images

with open('train.csv', 'rb') as trainfile:
    trainread = csv.reader(trainfile, delimiter=',', quotechar="'")
    trainread.next() # Skips header

    for row in trainread: # Reads image and digit
        row = [int(i) for i in row]
        digits.append(row[0])
        images.append(row[1:])


# In[3]:

## Test Dataset
test_images = []

with open('test.csv', 'rb') as testfile:
    testread = csv.reader(testfile, delimiter=',', quotechar="'")
    testread.next() # Skips header
    
    for row in testread:
        row = [int(i) for i in row]
        test_images.append(row)


# ### Submissions

# In[4]:

def submit(prediction,file):
    with open(file + '.csv', 'wb') as outfile:
        predwriter = csv.writer(outfile,delimiter=",",quotechar='|', quoting=csv.QUOTE_MINIMAL)
        
        predwriter.writerow(['ImageId','Label'])
        for i in range(len(prediction)):
            predwriter.writerow([i+1,prediction[i]])


# ### KNN Classifier

# In[5]:

## KNN Classifier
# Training
from sklearn import neighbors
from sklearn import cross_validation
from sklearn.cross_validation import StratifiedShuffleSplit

train = []
target = []
sample = StratifiedShuffleSplit(digits, 1, train_size=0.05, random_state=0)

for train_index,test_index in sample:
    for i in train_index:
        train.append(images[i])
        target.append(digits[i])
        
train = np.array(train)
target = np.array(target)


max_k=1000
maximum=0
k=0

for i in range(max_k):
    knn = neighbors.KNeighborsClassifier(n_neighbors=i+1)
    # Computing the mean of the cross validation accuracies
    score = cross_validation.cross_val_score(knn, train, target, cv=3, n_jobs=-1).mean()
    (k,maximum) = (i,score) if maximum < score else (k,maximum)
    
knn = neighbors.KNeighborsClassifier(n_neighbors=k+1)
knn.fit(images,digits)


# In[6]:

# Prediction
knn_prediction = knn.predict(test_images).tolist()


# In[8]:

# Submission
submit(knn_prediction,"digits_knn." + str(k))


# ###Random Forest

# In[5]:

## Random Forests Classifier
# Training
from sklearn.ensemble import RandomForestClassifier
k = 100
forest = RandomForestClassifier(n_estimators = 100, n_jobs=-1)
forest.fit(images, digits)


# In[6]:

# Prediction
forest_prediction = forest.predict(test_images).tolist()


# In[10]:

# Submission
submit(forest_prediction,"forest_digits1")


# ### Naive Bayes

# In[11]:

## Naive Bayes Classifier
# Training
from sklearn.naive_bayes import GaussianNB
nb = GaussianNB()
nb.fit(images, digits)


# In[12]:

# Prediction
nb_prediction = nb.predict(test_images).tolist()


# In[13]:

# Submission
submit(nb_prediction,"nbayes_digits1")


# In[ ]:



