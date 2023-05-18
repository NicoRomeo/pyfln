/*
 * Copyright (C) 2021 Nicolas Romeo <nromeo@mit.edu>.
 * Adapted from code Copyright (C) 2021 Ante Qu <antequ@cs.stanford.edu>.
 */
#include "linking_number_certificate.h"
#include "model.h"

#include <chrono>
#include <iostream>
#include <pybind11/pybind11.h>
#include <string>

using namespace VerifyCurves;

int fastlinks(const std::string &infilename,
              const std::string &outfilename,
              bool fast = 1,
              bool discretize = true,
              double bh_init_beta = 2.0,
              double bh_beta_limit = 10.0) {

    Model model;
    // Import the input model
    model.ImportFromFile(infilename);

    std::string output_filename = outfilename;

    bool use_direct_sum = false;
    if (fast == 0) {
        use_direct_sum = true;
    }

    LinkingNumberCertificate certificate;

    {
        std::string method_string = use_direct_sum ? "Direct Summation" : "Barnes–Hut";
        std::cout << "Computing the certificate using the " << method_string << " Method."
                  << std::endl;
        std::chrono::steady_clock::time_point compute_begin = std::chrono::steady_clock::now();
        certificate.ComputeFromModel(
            model, use_direct_sum, discretize, bh_init_beta, bh_beta_limit);
        std::chrono::steady_clock::time_point compute_end = std::chrono::steady_clock::now();
        int64_t compute_time
            = std::chrono::duration_cast<std::chrono::microseconds>(compute_end - compute_begin)
                  .count();
        std::cout << "Computation runtime: " << (1e-3 * compute_time)
                  << " ms. This includes all stages." << std::endl;
    }

    {
        std::cout << "Exporting the certificate to " << output_filename << "." << std::endl;
        std::chrono::steady_clock::time_point export_begin = std::chrono::steady_clock::now();
        certificate.ExportToFile(output_filename);
        std::chrono::steady_clock::time_point export_end = std::chrono::steady_clock::now();
        int64_t export_time
            = std::chrono::duration_cast<std::chrono::microseconds>(export_end - export_begin)
                  .count();
        std::cout << "Export runtime: " << (1e-3 * export_time) << " ms." << std::endl;
    }

    return 0;
}

namespace py = pybind11;

PYBIND11_MODULE(_pyfln, m) {
    m.doc() = "pybind11 wrapper for fast linking numbers";

    m.def("fastlinks",
          &fastlinks,
          "import bcc file and runs fast linking number on the curves",
          py::arg("infilename"),
          py::arg("outfilename"),
          py::arg("fast") = 1,
          py::arg("discretize") = true,
          py::arg("bh_init_beta") = 2.0,
          py::arg("bh_beta_limit") = 10.0);
}