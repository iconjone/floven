var minify = require('html-minifier').minify
const fs = require('fs')

const buffer = fs.readFileSync("index.html")

let result = minify(buffer.toString(),{
collapseBooleanAttributes: true,
collapseWhitespace: true,
minifyCSS: true,
minifyJS: true,
quoteCharacter: '\"'
})
fs.writeFile('index.min.html', result , function(err){if(!err)console.log("minified html generated.")})

result = result.replace(/"/g,'\\"')

fs.writeFile('index.min.txt', 'const char control_html_str[] PROGMEM = "' + result  + '";', function(err){if(!err)console.log("minified html text generated.")})