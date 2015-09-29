import os
from tap.parser import Parser

parser = Parser()
tests_result = []

o_tests= "id:{test_case_id} result:{result} message:{message}"

for root, dirs, files in os.walk("tap"):
    for file in files:
        if file.endswith(".tap"):
            tests_result.append(os.path.join(root, file))

expected_tests = 0
i = 0
for tests_file in tests_result:
    basename = os.path.splitext(os.path.basename(tests_file))[0]
    print(o_tests.format(
        test_case_id='{}-{}'.format(basename, 0),
        result='pass',
        message='Start of test suite for file {}'.format(basename)))

    for line in parser.parse_file(tests_file):
        # First line should be a plan
        if line.category == 'plan':
            expected_tests = line.expected_tests
        if line.category == 'test':
            # Remove '- ' from description
            description = line.description[2:]
            i = i + 1
            if line.skip :
                print(o_tests.format(test_case_id='{}-{}'.format(basename,
                    line.number),result='skip',
                    message=description))
            else:
                print(o_tests.format(test_case_id='{}-{}'.format(basename,
                    line.number),result=('pass' if line.ok else 'fail'),
                    message=description))

        if line.category == 'bail':
            print(o_tests.format(test_case_id='{}-{}'.format(basename,
                line.number),result='fail',
                message=line.reason))

        if line.category == 'unknown':
            print(o_tests.format(test_case_id='{}-{}'.format(basename,
                line.number),result='fail',
                message="Invalid tap output"))


    if expected_tests != -1 and expected_tests == i:
        print(o_tests.format(test_case_id='{}-plan'.format(basename),result=True,
            message='Expecting {} tests'.format(expected_tests)))
    else:
        print(o_tests.format(test_case_id='{}-plan'.format(basename),result=False,
            message=''))

    i = 0
    expected_tests = -1
