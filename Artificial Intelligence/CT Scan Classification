import numpy as np 
import pandas as pd
from skimage import io
import os
from os import listdir
from os.path import isfile, join
from torch.utils.data import Dataset, DataLoader
import torch
import pdb
from torchvision.transforms.functional import to_tensor, normalize
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import csv

#Pentru parcurgerea folderelor train respectiv validation:
train = [f for f in listdir("../input/dataset-competitie/train") if isfile(join("../input/dataset-competitie/train", f))]
test = [f for f in listdir("../input/dataset-competitie/validation") if isfile(join("../input/dataset-competitie/validation", f))]

imagini = []
imagini_test = []
nume_imagine = []

#Parcurgem folderul train si salvam in lista "imagini" imaginea + numele fisierului:
for file in train:
    imagine = io.imread("../input/dataset-competitie/train/" + file)
    imagini.append((imagine,file))
    
#Parcurgem folderul validation si salvam in lista "imagini_test" imaginea + numele fisierului:
for file in test:
    imagine = io.imread("../input/dataset-competitie/validation/" + file)
    imagini_test.append((imagine,file))
    
#Incarcam nume imagine + label    
train_images_labels = np.loadtxt('../input/dataset-competitie/train.txt', dtype=np.str,delimiter=",") 
test_images_labels = np.loadtxt('../input/dataset-competitie/validation.txt', dtype=np.str,delimiter=",")

for i in range (0,15000): #pentru setul de antrenare
    for j in range(0,15000):
        if(imagini[i][1]==train_images_labels[j][0]): #cautam numele imaginii si salvam doar imaginea + clasa ei
            imagini[i]=(imagini[i][0],train_images_labels[j][1])
            break
            
for i in range (0,4500): #pentru setul de testare
    for j in range(0,4500):
        if(imagini_test[i][1]==test_images_labels[j][0]): #cautam numele imaginii si salvam doar imaginea + clasa ei
            nume_imagine.append(imagini_test[i][1])
            imagini_test[i]=(imagini_test[i][0],test_images_labels[j][1])
            break


class TMDataset(Dataset):
    def __init__(self, imagini, img_labels):
        self.imagini = imagini
        self.img_labels = img_labels
        
        print(np.shape(self.imagini))
        print(np.shape(self.img_labels))
    def __len__(self):
        return len(self.imagini)

    def __getitem__(self, idx):
        img = self.imagini[idx]
        
        #aici am incercat normalizarea imaginii
        #img = to_tensor(img)
        #img = normalize(img, [0.5], [0.5]) 
        #img = img.reshape(img.shape[1:])
        
        img = np.array(img) / 255
        
        torch_img = torch.tensor(img).unsqueeze(0).float()

        label = torch.tensor(self.img_labels[idx])
        
        return torch_img, label
    
    
#Incarc imaginile si label-urile de train, respectiv validation si creez dataloaderele
tmds = TMDataset(np.array(imagini)[:,0], np.array(imagini)[:,1].astype(int)) 
tmds2 = TMDataset(np.array(imagini_test)[:,0], np.array(imagini_test)[:,1].astype(int))

my_dataloader = DataLoader(tmds, batch_size=1, shuffle=True)
my_dataloader2 = DataLoader(tmds2, batch_size=1, shuffle=True)


class MyConvNet(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=3, kernel_size=3)
        self.conv2 = nn.Conv2d(in_channels=3, out_channels=6, kernel_size=5, stride=2)
        
        self.norm1 = nn.BatchNorm2d(3)
        self.norm2 = nn.BatchNorm2d(6)
        #Aici am incercat sa folosesc dropout
        #self.dropout = nn.Dropout(0.2)
        
        self.pool = nn.MaxPool2d(2, 2)
        self.flatten = nn.Flatten()
        
        
        self.fc1 = nn.Linear(150, 50)
        self.fc2 = nn.Linear(50, 3)
        
        self.relu = nn.SELU()
        self.softmax = nn.Softmax(dim=1)

    def forward(self, x):
        x = self.conv1(x)
        x = self.norm1(x)
        x = self.relu(x)
        x = self.pool(x)
        
        x = self.conv2(x)
        x = self.norm2(x)
        x = self.relu(x)
        x = self.pool(x)
        
        x = self.flatten(x)
        x = self.fc1(x)
        x = self.relu(x)
        #Aici am incercat sa folosesc dropout
        #x = self.dropout(x)
        
        x = self.fc2(x)
        x = self.relu(x)
        #Aici am incercat sa folosesc dropout
        #x = self.dropout(x)
        
        x = self.softmax(x)
        return x
    
net = MyConvNet()
optimizer = optim.Adam(net.parameters(), lr=0.001)
criterion = nn.CrossEntropyLoss()

net.train() # pentru antrenare
#net.eval() # pentru validare

#Am ales sa antrenez pe 10 epoci
for e in range(10):
    for batch in my_dataloader:
        torch_img, label = batch
        optimizer.zero_grad()
        output = net(torch_img)

        predicted_label = torch.argmax(output, axis=1)
        loss = criterion(output, label)

        loss.backward()
        optimizer.step()
    print(loss)
        
    #De aici calculez rata de acuratete pe setul de antrenare
    count = 15000
    correct = 0

    for batch in my_dataloader:
        torch_img, label = batch
        prediction = torch.argmax(net(torch_img))
        if prediction.item() == label[0]:
            correct += 1
    print("Acuratetea la finalul epocii {} este",(correct / count) * 100)
    
    
    
#Pentru parcurgerea folderului test
submit_test = [f for f in listdir("../input/dataset-competitie/test") if isfile(join("../input/dataset-competitie/test", f))]    

submit_imagini = []

for file in submit_test:
    imagine = io.imread("../input/dataset-competitie/test/" + file)
    submit_imagini.append((imagine,file))

imagini_test_final = np.array(submit_imagini)[:,0]
nume_img = np.array(submit_imagini)[:,1]
#Pentru a crea un dataloader am folosit valori de la 0 la 3900 pentru etichete pentru a pastra structura programului,
#dar nu era necesar. 
nimic = [idx for idx in range(0,3900)]

tmds_test = TMDataset(np.array(imagini_test_final), np.array(nimic).astype(int))
my_dataloader_test = DataLoader(tmds_test, batch_size=1, shuffle=False)


#Pentru scrierea in fisierul cu predictii finale
i=0
with open('predictiePlus.csv', mode='w') as rezultate:
    rezultate = csv.writer(rezultate, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    rezultate.writerow(["id","label"])
    
    for batch in my_dataloader_test:
            torch_img, label = batch
            output = net(torch_img)

            predicted_label = torch.argmax(output, axis=1)
            rezultate.writerow([nume_img[i], predicted_label.item()])
            i=i+1
            
            
            
#Am folosit codul urmator pentru testarea diferitelor functii de activare, configuratii ale retelei, rate de invatare si 
#numar de epoci (acest cod era intr-un cell separat)
"""
net = MyConvNet()
optimizer = optim.Adam(net.parameters(), lr=0.001)
criterion = nn.CrossEntropyLoss()

test = [f for f in listdir("../input/dataset-competitie/validation") if isfile(join("../input/dataset-competitie/validation", f))]
imagini_testare=[]
for file in test:
    imagine = io.imread("../input/dataset-competitie/validation/" + file)
    imagini_testare.append((imagine,file))

net.train() 
#net.eval() 
for e in range(20):
    for batch in my_dataloader:
        torch_img, label = batch
        optimizer.zero_grad()
        output = net(torch_img)


        predicted_label = torch.argmax(output, axis=1)
        loss = criterion(output, label)

        loss.backward()
        optimizer.step()


    print(loss)
        
    count = 15000
    correct = 0

    for batch in my_dataloader:
        torch_img, label = batch
        prediction = torch.argmax(net(torch_img))
        if prediction.item() == label[0]:
            correct += 1

    print("Acuratetea la finalul epocii {} este",(correct / count) * 100)   
    
    correct = 0    
    i=0
    print("id,label")
    for batch in my_dataloader2:
        torch_img, label = batch
        
        prediction = torch.argmax(net(torch_img))
        #print("%s,%s" % (nume_imagine[i], prediction.item()))
        i=i+1
        if prediction.item() == label[0]:
            correct += 1

    print("Acuratetea pentru dataset-ul de validare este",(correct / 4500) * 100) 
if correct/4500 >=70:
    break

"""


#Aici am antrenat reteaua pe setul de antrenare+validare
"""
imagini_plus = np.concatenate((np.array(imagini)[:,0], np.array(imagini_test)[:,0]),axis= None)
label_plus = np.concatenate((np.array(imagini)[:,1], np.array(imagini_test)[:,1]),axis= None)

tmds_plus = TMDataset(imagini_plus, label_plus.astype(int))

my_dataloader_plus = DataLoader(tmds_plus, batch_size=1, shuffle=True)

net = MyConvNet()
optimizer = optim.Adam(net.parameters(), lr=0.001)
criterion = nn.CrossEntropyLoss()

test = [f for f in listdir("../input/dataset-competitie/validation") if isfile(join("../input/dataset-competitie/validation", f))]
imagini_testare=[]
for file in test:
    imagine = io.imread("../input/dataset-competitie/validation/" + file)
    imagini_testare.append((imagine,file))

net.train()
#net.eval()
for e in range(15):
    for batch in my_dataloader_plus:
        torch_img, label = batch
        optimizer.zero_grad()
        output = net(torch_img)
        predicted_label = torch.argmax(output, axis=1)
        loss = criterion(output, label)
        loss.backward()
        optimizer.step()
    print(loss)
        
    count = 19500
    correct = 0

    for batch in my_dataloader_plus:
        torch_img, label = batch
        
        prediction = torch.argmax(net(torch_img))
        if prediction.item() == label[0]:
            correct += 1

    print("Acuratetea la finalul epocii {} este",(correct / count) * 100)   
    
    correct = 0    
    print("id,label")
    for batch in my_dataloader2:
        torch_img, label = batch
        
        prediction = torch.argmax(net(torch_img))
        if prediction.item() == label[0]:
            correct += 1
"""
