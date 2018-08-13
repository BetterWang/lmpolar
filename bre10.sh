cp batch_101_10.sh batch_$1_10.sh
sed -i "s/101/$1/" batch_$1_10.sh
#bsub -q 8nh batch_$1_10.sh
