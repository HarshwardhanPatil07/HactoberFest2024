import pandas as pd
import matplotlib.pyplot as plt
from scipy.cluster.vq import kmeans,vq,whiten
import matplotlib.image as image
import seaborn as sns
img=image.imread('images.jpg')
print(img.shape)
r=[]
b=[]
g=[]
for pixel in img:
    for r_temp,b_temp,g_temp in pixel:
        r.append(r_temp)    
        b.append(b_temp)
        g.append(g_temp)
img_df=pd.DataFrame({'red':r,'blue':b,'green':g})
img_df["scaled_r"]=whiten(r)
img_df["scaled_b"]=whiten(b)
img_df["scaled_g"]=whiten(g)
distortions=[]
num_clusters=range(1,7)
for i in num_clusters:
    centroids,distortion =kmeans(img_df[['scaled_r','scaled_b','scaled_g']],i) 
    distortions.append(distortion)
elbow_plot = pd.DataFrame({'num_clusters':num_clusters,'distortions':distortions})
sns.lineplot(x='num_clusters',y='distortions',data=elbow_plot)
plt.xticks(num_clusters)
plt.show()
#we get optimal centroids as 3 so we compute centroids with 3 clusters
cluster_centroids,_ =kmeans(img_df[['scaled_r','scaled_b','scaled_g']],3)
r_std, g_std, b_std = img_df[['red', 'green', 'blue']].std()
colors=[]
for r,b,g in cluster_centroids:
    colors.append((r *r_std/255
                   ,b*b_std/255
                   ,g*g_std/255))
plt.imshow([colors])
plt.show()