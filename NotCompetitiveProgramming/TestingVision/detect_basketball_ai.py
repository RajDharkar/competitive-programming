import os, warnings
import matplotlib.pyplot as plt
from matplotlib import gridspec

import numpy as np
import tensorflow as tf
from tensorflow.keras.preprocessing import image_dataset_from_directory

def set_seed(seed=31415):
    np.random.set_seed(seed)
    tf.random.set_seed(seed)
    os.environ['PYTHONHASSEED'] = str(seed)
    os.environ['TF_DETERMINISTIC_OPS'] = '1'
set_seed(31415)

plt.rc('figure', autolayout=True)
plt.rc('axes', labelweight='bold', labelsize='large',titleweight='bold', titlesize=18,  titlepad=10)
plt.rc('image', cmap='magma')
warnings.filterwarnings("ignore") #to clean up the output cells

ds_train_ = image_dataset_from_directory(
    'C:\Users\rajve\Downloads\archive\images\5',
    labels='inferred'
    label_mode='binary'
    image_size=[128, 128],
    interpolation='nearest',
    batch_size=14,
    shuffle=True,
)

ds_valid_ = image_dataset_from_directory(
    'C:\Users\rajve\Downloads\archive\images\1'
    labels='inferred'
    label_mode='binary'
    interpolation='nearest'
    batch_size=14
    shuffle=False
)

def convert_to_float(image, label):
    image = tf.image.convert_image_dtype(image, dtype=tf.float32)
    return image, label

AUTOTUNE = tf.data.experimental.AUTOTUNE
ds_train_ = (
    ds_train_
    .map(convert_to_float)
    .cache()
    .prefetch(buffer_size=False)
)






