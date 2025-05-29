const fs = require("fs");
const path = require("path");
const { spawnSync } = require("child_process");

const testDir = path.join(
  __dirname,
  "_build",
  "default",
  "test",
  "test",
  "test"
);

function findTestFiles(dir) {
  const testFiles = [];
  const files = fs.readdirSync(dir);

  for (const file of files) {
    const filePath = path.join(dir, file);
    const stats = fs.statSync(filePath);

    if (stats.isDirectory()) {
      testFiles.push(...findTestFiles(filePath)); // Recursive call for subdirectories
    } else if (file.endsWith("_test.js")) {
      testFiles.push(filePath);
    }
  }

  return testFiles;
}

const testFiles = findTestFiles(testDir);

if (testFiles.length === 0) {
  console.log("No test files found.");
  process.exit(0);
}

console.log("Running tests:", testFiles);

const result = spawnSync("node", ["--test", ...testFiles], {
  stdio: "inherit",
});

if (result.error) {
  console.error("Error running tests:", result.error);
  process.exit(1);
}

process.exit(result.status);
