#ifndef LITERALS_H
#define LITERALS_H

#define MONGOOSELITERAL "const mongoose = require(\"mongoose\")\n\
const url = require(\"./url\").mongooseurl(\"task-manager\")\n\
const port = require(\"./url\").port\n\
const host = require(\"./url\").host\n\
\n\
mongoose.Promise = global.Promise\n\
\n\
mongoose.connect(url, {\n\
    \tuseNewUrlParser: true,\n\
    \tuseCreateIndex: true,\n\
    \tuseUnifiedTopology: true,\n\
    \tuseFindAndModify: false,\n\
}, () => {\n\
    console.log(`Connected to mongo server on host ${host} port ${port}`)\n\
})"
#define URLLITERAL  "const username = \"\"\n\
const password = \"\"\n\
const host = \"localhost\"\n\
const port = 27017\n\
const mongourl = `mongodb://${username}:${password}@${host}:${port}/?authSource=admin`\n\
\n\
const mongooseurl = (db) => {\n\
    return `mongodb://${username}:${password}@${host}:${port}/${db}?authSource=admin`\n\
}\n\
module.exports = {\n\
    mongourl: mongourl,\n\
    mongooseurl: mongooseurl,\n\
    port: port,\n\
    host: host,\n\
}"
#define APPLITERAL "require(\"./db/mongoose\")\n\
const express = require(\"express\")\n\
\n\
const app = express()\n\
\n\
const port = process.env.PORT || 3000\n\
//Routers come here\n\
\n\
\n\
app.use(express.json())\n\
\n\
app.listen(port, () => {\n\
    console.log(`Server is running on port ${port}`)\n\
})"
#define MODELLITERAL "const mongoose = require(\"mongoose\")\n\
const %sSchema = new mongoose.Schema({\n\
\n\
})\n\
const %s = mongoose.model(\"%s\", %sSchema)\n\
module.exports = %s"
#define ROUTERLITERAL "const %s = require(\"../models/%s\");\n\
const express = require(\"express\");\n\
const router = new express.Router();\n\
\n\
router.post(\"\", (req, res) => {\n\
   \n\
});\n\
router.get(\"\", (req, res) => {\n\
\n\   
});\n\
router.patch(\"\", (req, res) => {\n\
\n\   
});\n\
router.delete(\"\", (req, res) => {\n\
\n\   
});\n\
\n\
module.exports = router;"
#define ADDROUTERLITERAL "\nconst %sRouter = require(\"./db/routers/%s\")\n\
app.use(%sRouter)\n"
#define NPMLITERAL "\t\t\"test\": \"nodemon src/index.js --ext js,hbs,css,mjs,json\"\n"
#define GITIGNORELITERAL "url.js"
#endif