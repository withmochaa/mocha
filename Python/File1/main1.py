from PIL import Image
import os,glob
import numpy as np
from sklearn.model_selection import train_test_split


caltech_dir="C:\Data\screw"
categories=["normal","adnormal"]
nb_classes=len(categories)



image_w=64
image_h=64
pixels=image_w*image_h*3



X=[]
Y=[]

for idx,cat in enumerate(categories):
    label=[0 for i in range(nb_classes)]
    label[idx]=1
    image_dir=caltech_dir+"/"+cat
    files=glob.glob(image_dir+"/*.jpg")
    for i, f in enumerate(files):
        img = Image.open(f)
        img=img.convert("RGB")
        img=img.resize((image_w,image_h))
        data=np.asarray(img)
        X.append(data)
        Y.append(label)
        if i%10==0:
            print(i,'\n',data)
            
X=np.array(X)
Y=np.array(Y)
X_train, X_test, y_train, y_test=train_test_split(X, Y,stratify=Y)
xy=(X_train,X_test,y_train,y_test)
np.save("C:\Data\screw\data.npy",xy)
print("ok",len(Y))








from keras.models import Sequential
from keras.layers import Convolution2D, MaxPooling2D
from keras.layers import Activation,Dropout,Flatten,Dense
import numpy as np
import tensorflow




categories=["normal","adnormal"]
nb_classes=len(categories)

image_w=64
image_h=64

X_train,X_test,y_train,y_test=np.load("C:\Data\screw\data.npy",allow_pickle=True)

X_train=X_train.astype("float")/256
X_test=X_test.astype("float")/256

print('X_train shape:',X_train.shape)







model = Sequential()
model.add(Convolution2D(32, 3, 3, 
    padding='same',
    input_shape=X_train.shape[1:]))
model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2),padding='same'))
model.add(Dropout(0.25))

model.add(Convolution2D(64, 3, 3, padding='same'))
model.add(Activation('relu'))
model.add(Convolution2D(64, 3, 3))
model.add(MaxPooling2D(pool_size=(2, 2),padding='same'))
model.add(Dropout(0.25))

model.add(Flatten()) # --- (※3) 
model.add(Dense(512))
model.add(Activation('relu'))
model.add(Dropout(0.5))
model.add(Dense(nb_classes))
model.add(Activation('softmax'))

model.compile(loss='binary_crossentropy',
    optimizer='rmsprop',
    metrics=['accuracy'])

# 모델 훈련하기 --- (※4)
model.fit(X_train, y_train, batch_size=32, epochs=50)
    
# 모델 평가하기--- (※5)
score = model.evaluate(X_test, y_test)
print('loss=', score[0])
print('accuracy=', score[1])