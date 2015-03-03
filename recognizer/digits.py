
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

# In[14]:

## KNN Classifier
# Training
from sklearn import neighbors
k = 1
knn = neighbors.KNeighborsClassifier(n_neighbors=k)
knn.fit(images, digits)


# In[15]:

# Prediction
knn_prediction = knn.predict(test_images).tolist()


# In[16]:

# Submission
submit(knn_prediction,"digits_knn1.s")


# ###Random Forest

# In[8]:

## Random Forests Classifier
# Training
from sklearn.ensemble import RandomForestClassifier
k = 100
forest = RandomForestClassifier(n_estimators = 100, n_jobs=6)
forest.fit(images, digits)


# In[9]:

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



