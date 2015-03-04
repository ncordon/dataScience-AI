# Diabetes data
diabetes <- read.csv("pima-indians-diabetes.data")
names(diabetes) <- c("Pregnant","Glucose","BloodPressure","SkinThickness","Insulin","MassIndex","Pedigree","Age","Diabetes")
summary(diabetes)

# Decision tree
library(rpart)
fit <- rpart(Diabetes ~ Glucose + BloodPressure + SkinThickness + Age,
             method="class", data=diabetes)

# Plot
plot(fit, uniform=TRUE,
     main="Pima indians diabetes")
text(fit, use.n=TRUE, all=TRUE, cex=.8)

post(fit, file = "./tree.ps",
     title = "Diabetes decision tree")
