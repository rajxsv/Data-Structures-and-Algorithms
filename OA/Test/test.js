const fs = require("node:fs");

(() => {
    fs.open("test.txt", "w", (err, fd) => {
        for (let i = 0; i < 10; i++) {
            fs.write(fd, `${i} `, (_, written, str) => {
                for (let k = 0; k < 100000; k++) { }
                console.log({ i, fd, written, str })
                for (let k = 0; k < 100000; k++) { }
            })
        }
    })
})()
