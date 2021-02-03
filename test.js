const { togglePopup, showPopup, hidePopup } = require('./');

const tests = {
  toggle: togglePopup,
  show: showPopup,
  hide: hidePopup
};

const test = process.argv[2];

if (test && tests.hasOwnProperty(test)) {
  tests[test]();
} else {
  console.error('Specify test name');
}
