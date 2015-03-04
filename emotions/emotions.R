#
# Multilabel classification of music into emotions
# with Binary Relevance transformation using kNN
# as base classifier
#

# Load packages
library(mldr)
library(RWeka)

# Basic info about dataset
summary(emotions)
emotions$labels
plot(emotions, type = "LC")

# Data partitioning
train <- emotions[1:500]
test <- emotions[500:593]
test_instances <- test$dataset[, 1:(emotions$measures$num.attributes - emotions$measures$num.labels)]

# BR transformation
emo_br <- mldr_transform(train, type = "BR")
emo_br <- lapply(emo_br, function(ds) {
  names(ds)[length(ds)] <- "label"
  ds
})

# Predictions for test instances
predicted <- data.frame(sapply(emo_br, function(ds) {
  cl <- IBk(label ~ ., data = ds, control = Weka_control(K = 6))
  round(predict(cl, test_instances))
}))
names(predicted) <- row.names(emotions$labels)

# Preliminary accuracy measures
diff <- abs(test$dataset[, emotions$labels$index] - predicted)
colSums(diff)