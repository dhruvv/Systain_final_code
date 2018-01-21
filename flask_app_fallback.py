from flask import Flask, render_template, jsonify
import requests
app = Flask(__name__)

data = {}
data = requests.get(url="http://oakhack.pythonanywhere.com")
turb = data.json()
val = turb["turbidity"]

@app.route('/', methods = ['GET'])
def get():
    if(val>2700):
        return jsonify('Sensor not in water')
    elif(val<=2700 and val>2000):
        return jsonify('Water fine.')
    elif(val<=2000 and val>1000):
        return jsonify('Water impure.')
    else:
        return jsonify('Water dangerous.')

if(__name__ == '__main__'):
    app.run(host = "0.0.0.0")
