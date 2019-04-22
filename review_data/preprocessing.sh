sed 's/^.*Text": "//g' reviews_Amazon_Instant_Video_5.json > 1.txt;
sed 's/, "summary".*$//g' 1.txt > 2.txt;
sed 's/", "overall": /|/g' 2.txt > 3.txt;
awk -F\| '{print $2"|"$1}' 3.txt > 4.txt;
awk '{print toupper($0)}' 4.txt > 5.txt;
sed 's/[^12345ABCDEFGHIJKLMNOPQRSTUVWXYZ| ]/ /g' 5.txt > 6.txt;
# > EDITED_REVIEWS.txt
rm 1.txt 2.txt 3.txt 4.txt 5.txt;
