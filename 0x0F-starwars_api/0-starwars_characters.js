#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];
request(url, function (err, res, body) {
  if (err) throw err;
  const chars = JSON.parse(body).characters;
  charsInOrder(chars, 0);
});
const charsInOrder = (chars, x) => {
  if (x === chars.length) return;
  request(chars[x], function (err, res, body) {
    if (err) throw err;
    console.log(JSON.parse(body).name);
    charsInOrder(chars, x + 1);
  });
};
